package searchgem5.gen.llm;

import java.io.IOException;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.net.URISyntaxException;

import io.github.amithkoujalgi.ollama4j.core.OllamaAPI;
import io.github.amithkoujalgi.ollama4j.core.models.OllamaResult;
import io.github.amithkoujalgi.ollama4j.core.types.OllamaModelType;
import io.github.amithkoujalgi.ollama4j.core.utils.PromptBuilder;
import io.github.amithkoujalgi.ollama4j.core.utils.OptionsBuilder;
import io.github.amithkoujalgi.ollama4j.core.exceptions.OllamaBaseException;

import searchgem5.gen.llm.LLMTokensOptions;
import searchgem5.gen.llm.TestInputWriter;
import searchgem5.gen.llm.Parser;

class ProgramGenerator {
    public void loadModel(OllamaAPI ollamaAPI, String modelType, String prompt) {
        try {
            // code that might throw OllamaBaseException
            ollamaAPI.pullModel(modelType);
        } catch (OllamaBaseException e) {
            // handle the exception
            e.printStackTrace();
        } catch (IOException | InterruptedException | URISyntaxException e) {
            // handle the IOException
            e.printStackTrace();
        }
    }

    public String askModel(OllamaAPI ollamaAPI, String modelType, String prompt) {
        try {
            // code that might throw OllamaBaseException
            OllamaResult result =
                    ollamaAPI.ask(modelType, prompt, new OptionsBuilder().build());
            //System.out.println(result.getResponse());
            return result.getResponse();
        } catch (OllamaBaseException e) {
            // handle the exception
            e.printStackTrace();
        } catch (IOException | InterruptedException e) {
            // handle the IOException
            e.printStackTrace();
        }
        return "";
    }

    public static void main(String[] args) {
	/// Start of the program ///
	long startTime = System.nanoTime();
	long maxDurationInMillis = 25 * 60 * 60 * 1000; // Convert hours to milliseconds
	long endTime = startTime + maxDurationInMillis; // Just to make it easier to read
        System.out.println("Hello, Starting Generating Programs!");


	/// Actual program ///

        // Upload model
        String host = "http://localhost:11434/";
        OllamaAPI ollamaAPI = new OllamaAPI(host);
        ollamaAPI.setRequestTimeoutSeconds(100);
        ollamaAPI.setVerbose(true);
        boolean isOllamaServerReachable = ollamaAPI.ping();
        System.out.println("Is Ollama server alive: " + isOllamaServerReachable);


	// Model type: https://github.com/amithkoujalgi/ollama4j/blob/816bbd9bbf5550bacdfeef7252bfcdf53c8697a5/src/main/java/io/github/amithkoujalgi/ollama4j/core/types/OllamaModelType.java#L10
        String modelType = OllamaModelType.MAGICODER;
	//String modelType = OllamaModelType.PHI;
	//String modelType = OllamaModelType.DEEPSEEK_CODER;

        ProgramGenerator compilerStrings = new ProgramGenerator();
	LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();
	TestInputWriter writer = new TestInputWriter();
	Parser parser = new Parser();

        // Let LLM know what we want:
        String promtStart = "Generate a concise C file without unnecessary includes, but with output. The C file should be a standard program, but with a twist:"
                + " it replaces all constants in the main function with argument assignments, adds required includes.";
        promtStart += "Example ```C\n#include <stdio.h>\n#include <stdlib.h>\nint main(int argc, char *argv[]) {\n"
                + "  if (argc != 2) {\n    printf(''Usage: %s <value>\n'', argv[0]);\n    return 1;\n  }\n  int x = atoi(argv[1]);\n"
                + "  return x - 4;\n}```\nDo you think you can do that?";
        compilerStrings.askModel(ollamaAPI, modelType, promtStart); // If not crash continue.

	// Start test input generation
        while (true) {
            // Get a random entry from each array
            String randomCompilerOpt = llmIndexedTokens.getRandomCompilerOpt();
            String randomCompilerParts = llmIndexedTokens.getRandomCompilerParts();
            String randomPL = llmIndexedTokens.getRandomPL();

            // Combine the random entries into a prompt string
            //String promptString = "Prompt: " + randomCompilerOpt + ", " + randomCompilerParts + ", " + randomPL;

            // Example: This is a code-generation task. Give me a program in C with all includes. Code only and short answer. Input is taken via argv only. Please return a program (C program) and an example of input (BASH).
            // The C program will be with code triggering Memory Optimizations optimization, covers this part of the compiler Handles code generation, and exercises this idea in C: acquire operation.
            // program
            String prompt = "Coding task: give me a program in C with all includes. Input is taken via argv only. Please return a program (C program) and a concrete example of an input (BASH). " +
                    "The C program will be with code triggering " + randomCompilerOpt + " optimizatios, covers this part of the compiler " +
                    randomCompilerParts + ", and excersises this idea in C: " + randomPL + ".";

            // PROMPT
            String res = compilerStrings.askModel(ollamaAPI, modelType, prompt);
            System.out.println(res);

            // Program
            String program = parser.getCProgram(res);
            System.out.println("======================= Program: =======================");
            System.out.println(program);

            // Input
            String callLine = parser.getArgsInput(res);
            System.out.println("======================= Input: ======================="); // Solve problem with "./" in second bash tags
            System.out.println(callLine);

            // Type
            String argsType = parser.getTypes(res, callLine);
            System.out.println("======================= Type: =======================");
            System.out.println(callLine + ":" + argsType);

            // Check if we need to stop - but before writing the test - to be fair.
            if (System.currentTimeMillis() > endTime) {
		System.out.println("System has been running for more 25 hours. Exiting...");
		break;
	    }

	    // Try write the generated tests
            if (writer.writeTest(program, callLine, argsType)) {
                System.out.println(">>>>>> Generate the test input okay. <<<<<<");
                System.out.println("===========================================================================");
            }
        }
    }
}
