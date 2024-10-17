/**
 * @file ProgramGenerator.java
 *
 * @brief Generate test input for the input corpus for SearchGem5 method via LLM models.
 *
 *
 * @copyright (C) 2023,2024 Aidan Dakhama, Karine Even-Mendoza, William B. Langdon, 
 *                      Hector D. Menendez, Justyna Petke.
 *                King's College London and UCL University College London.
 *
 * This JAVA file is part of SearchGem5 Project.
 *
 * SearchGem5 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * SearchGem5 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * Please note that this copyright notice applies specifically to this header file.
 * Different components of your project may have their own licensing terms.
 */
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

    // If the model is not there, we can pull it automatically!
    public void loadModel(OllamaAPI ollamaAPI, String modelType) {
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


        // Check if the correct number of command-line arguments is provided
        if (args.length != 2) {
            System.out.println("Usage: java Main <modelType> <isToPullModel>");
            System.exit(1); // Exit with an error code
        }


        // Model type: https://github.com/amithkoujalgi/ollama4j/blob/816bbd9bbf5550bacdfeef7252bfcdf53c8697a5/src/main/java/io/github/amithkoujalgi/ollama4j/core/types/OllamaModelType.java#L10
        boolean isToPullModel = Boolean.parseBoolean(args[1]);
	String modelType = args[0];
        if (isToPullModel) {
	    // Must be a valid model type
            try {
                // Use reflection to check if the constant exists in OllamaModelType
                OllamaModelType.class.getField(modelType.toUpperCase());
            } catch (NoSuchFieldException | SecurityException e) {
		System.out.println("Failed to create test input files because model is not ollama valid.");
                System.exit(1); // Exit with an error code
            }
	}

	//OllamaModelType.MAGICODER;
        //String modelType = OllamaModelType.PHI;
        //String modelType = OllamaModelType.DEEPSEEK_CODER


        // Upload model
        String host = "http://localhost:11434/";
        OllamaAPI ollamaAPI = new OllamaAPI(host);
        ollamaAPI.setRequestTimeoutSeconds(100);
        ollamaAPI.setVerbose(true);
        boolean isOllamaServerReachable = ollamaAPI.ping();
        System.out.println("Is Ollama server alive: " + isOllamaServerReachable);

	// Set all objects we need
        ProgramGenerator compilerStrings = new ProgramGenerator();
	LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();
	TestInputWriter writer = new TestInputWriter();
	Parser parser = new Parser();

	// If from Ollama DB - can pull it
	if (isToPullModel)
	    compilerStrings.loadModel(ollamaAPI, modelType);

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
                    randomCompilerParts + ", and excersises this idea in C: " + randomPL + ". To recup the code contains these: " + randomCompilerOpt + " and " + randomCompilerParts + " and " + randomPL;

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
