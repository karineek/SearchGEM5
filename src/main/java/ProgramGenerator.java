package searchgem5.gen.llm;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;
import java.util.Random;
import java.net.URISyntaxException;
import java.util.regex.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;

import io.github.amithkoujalgi.ollama4j.core.OllamaAPI;
import io.github.amithkoujalgi.ollama4j.core.models.OllamaResult;
import io.github.amithkoujalgi.ollama4j.core.types.OllamaModelType;
import io.github.amithkoujalgi.ollama4j.core.utils.PromptBuilder;
import io.github.amithkoujalgi.ollama4j.core.utils.OptionsBuilder;
import io.github.amithkoujalgi.ollama4j.core.exceptions.OllamaBaseException;

import searchgem5.gen.llm.LLMTokensOptions;
import searchgem5.gen.llm.TestInputWriter;

class ProgramGenerator {
    private static final Random random = new Random();

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

    public String getCode(String input, String cCodeRegex) {
        String[] lines = input.split("\\r?\\n");
        if (1 > lines.length) return "";
        try {
            Pattern cPattern = Pattern.compile(cCodeRegex, Pattern.DOTALL);

            // Get the block
            int i = 0;
            Matcher cMatcher = cPattern.matcher(lines[0]);
            // Print C code blocks
            while (!cMatcher.find()) {
                i++;
                if (i > lines.length) return "";
                cMatcher = cPattern.matcher(lines[i]);
            }
            // Yeah! we found it!
            // Jump to the start (we do not need the first i matched
            i++;

            // Pattern and Matcher for end of Code code
            if (i > lines.length) return "";
            String cCodeRegexEnd = "```*";
            Pattern cPatternEnd = Pattern.compile(cCodeRegexEnd, Pattern.DOTALL);
            Matcher cMatcherEnd = cPatternEnd.matcher(lines[i]);
            String program = "";
            while (!cMatcherEnd.find()) {
                program += "\n" + lines[i];
                i++;
                if (i > lines.length) return "";
                cMatcherEnd = cPatternEnd.matcher(lines[i]);
            }
            return program;
        } catch (PatternSyntaxException | ArrayIndexOutOfBoundsException e) {
            return "";
        }
    }

    public String getParams(String input) {
        // Define regular expressions for BASH code blocks
        String bashCodeRegex = "\\$.*?(?:\\n|$)";
        // Pattern and Matcher for BASH code
        Pattern bashPattern = Pattern.compile(bashCodeRegex);
        Matcher bashMatcher = bashPattern.matcher(input);
        // Print BASH code blocks
        while (bashMatcher.find()) {
            String bashBlock = (bashMatcher.group().trim());
            if (!bashBlock.contains("gcc") && !bashBlock.contains("clang")) {
                return bashBlock;
            }
        }
        return "0";
    }

    public static int getMaxArgvNumber(String input) {
        if (input.isEmpty()) return -1;

        Pattern pattern = Pattern.compile("argv\\[(\\d+)]");
        Matcher matcher = pattern.matcher(input);

        int maxArgvNumber = -1;

        while (matcher.find()) {
            int argvNumber = Integer.parseInt(matcher.group(1));
            maxArgvNumber = Math.max(maxArgvNumber, argvNumber);
        }

        return maxArgvNumber;
    }

    // Util
    public static String stringLeft(String input, String substring, int offset) {
        // Find the index of "./" in the input string
        int index = input.indexOf(substring);
        // If "./" is found, extract the substring after it
        return ((index != -1) && (index + offset < input.length())) ?
                input.substring(index + offset) : "";
    }

    public static String formatText(String inputText) {
        if (inputText.contains("bash")) {
            return "bash";
        } else if (inputText.contains("BASH")) {
            return "BASH";
        } else if (inputText.contains("Bash")) {
            return "Bash";
        } else if (inputText.contains("shell")) {
            return "shell";
        } else if (inputText.contains("Shell")) {
            return "Shell";
        } else if (inputText.contains("SHELL")) {
            return "SHELL";
        } else {
            // Default case: return the original text
            return "";
        }
    }

    private static String determineType(String input) {
        if (input.isEmpty()) return "STRING";

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("f")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                Float.parseFloat(withoutSuffix);
                return "FLOAT";
            } catch (NumberFormatException eFloat) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("ll") || input.endsWith("LL")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 2);
            try {
                Long.parseLong(withoutSuffix);
                return "LONG";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("ul") || input.endsWith("UL")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 2);
            try {
                return (Long.parseLong(withoutSuffix) >= 0) ? "ULONG" : "STRING";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("l") || input.endsWith("L")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                Long.parseLong(withoutSuffix);
                return "LONG";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        // Check if it ends with "f," "l," or "u"
        if (input.endsWith("u") || input.endsWith("U")) {
            // Remove the suffix and check if it can be parsed as a float
            String withoutSuffix = input.substring(0, input.length() - 1);
            try {
                return (Long.parseLong(withoutSuffix) >= 0) ? "UINT32" : "STRING";
            } catch (NumberFormatException eLong) {
                return "STRING";
            }
        }

        try {
            // Attempt to parse as Integer
            Integer.parseInt(input);
            return "INT32";
        } catch (NumberFormatException eInt) {
            // Not an Integer, check if it's a Double
            try {
                Double.parseDouble(input);
                return "DOUBLE";
            } catch (NumberFormatException eDouble) {
                // Not a Double mst be String
                return "STRING";
            }
        }
    }

    public static String getArgumentsTypes(String argsValue, int argsSize) {
        String returnTypesList = "BINARY";
        int currentListSize = 0;

        // Guess the type
        if (!argsValue.isEmpty()) {
            String[] args = argsValue.split(" ");
            for (String arg : args) {
                String type = determineType(arg);
                returnTypesList += " " + type;
                currentListSize++;
            }
        }

        // Fill remaining slots with INT32 if needed
        for (int i = currentListSize + 1; i <= argsSize; i++) {
            returnTypesList += " INT32";
            argsValue += (i == 0) ? "0" : " 0";
        }

        // Trim to remove leading space
        return returnTypesList.trim();
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

        // Let LLM know what we want:
        String promtStart = "Generate a concise C file without unnecessary includes, but with output. The C file should be a standard program, but with a twist:"
                + " it replaces all constants in the main function with argument assignments, adds required includes.";
        promtStart += "Example ```C\n#include <stdio.h>\n#include <stdlib.h>\nint main(int argc, char *argv[]) {\n"
                + "  if (argc != 2) {\n    printf(''Usage: %s <value>\n'', argv[0]);\n    return 1;\n  }\n  int x = atoi(argv[1]);\n"
                + "  return x - 4;\n}```\nDo you think you can do that?";
        compilerStrings.askModel(ollamaAPI, modelType, promtStart); // If not crash continue.

        long startTime = System.nanoTime();

        while (true) {
            // Get a random entry from each array
            String randomCompilerOpt = llmIndexedTokens.getRandomCompilerOpt();
            String randomCompilerParts = llmIndexedTokens.getRandomCompilerParts();
            String randomPL = llmIndexedTokens.getRandomPL();

            // Combine the random entries into a prompt string
            String promptString = "Prompt: " + randomCompilerOpt + ", " + randomCompilerParts + ", " + randomPL;

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
            System.out.println("======================= Program: =======================");
            String CString = (res.contains("```c*") ? "```c*" : "```C*");
            String program = compilerStrings.getCode(res, CString);
            System.out.println(program);
            // Input
            System.out.println("======================= Input: ======================="); // Solve problem with "./" in second bash tags
            String bashForm = formatText(res);
            String inputCleaned = stringLeft(compilerStrings.getCode(res, "```" + bashForm + "*"), "./", 2);
            if (inputCleaned.isEmpty()) {
                inputCleaned = compilerStrings.getCode(res, "```\n" + bashForm + "./*");
                if (inputCleaned.isEmpty()) {
                    inputCleaned = compilerStrings.getCode(res, "```\n./*");
                    if (inputCleaned.isEmpty()) {
                        inputCleaned = compilerStrings.getCode(res, "`./*");
                    }
                }
            }
            String[] lines = inputCleaned.split("\\r?\\n");
            String inputFirstLine = (lines.length == 0 ? inputCleaned : lines[0]);   // If not empty, but parsing failed, try to take the original results
            String callLine = (inputFirstLine.isEmpty() ? "0" : // If empty, we failed getting input.
                    stringLeft(inputFirstLine, " ", 0));
            // Remove leading space
            callLine = callLine.trim();
            while (callLine.length() > 0 && callLine.charAt(0) == ' ') {
                callLine = callLine.substring(1);
            }
            System.out.println(callLine);
            // Type
            System.out.println("======================= Type: =======================");
            int maxArgs = getMaxArgvNumber(program);
            System.out.println(maxArgs);
            String argsType = "";
            if (program.contains("argv[i]") || program.contains("argv[j]") || (maxArgs > 0)) {
                // set argsType
                argsType = getArgumentsTypes(callLine, maxArgs);
            }
            System.out.println(callLine + ":" + argsType);

            // Check if we need to stop - but before writing the test - to be fair.
            if (System.currentTimeMillis() > endTime) {
		System.out.println("System has been running for more" + hours + " hours. Exiting...");
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
