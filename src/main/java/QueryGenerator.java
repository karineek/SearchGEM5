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

class QueryGenerator {

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

    	if (args.length > 3) {
            System.out.println("Please provide a single parameter (0, 1, or 2).");
            // Optionally, you can exit the program here if the number of parameters is incorrect
            System.exit(1);
        }

	// Parse the parameter as an integer
        int parameter;
        try {
            parameter = Integer.parseInt(args[1]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid parameter. Please provide a valid integer (0, 1, or 2).");
            System.exit(1);
            return; // Unreachable, but included for clarity
        }

        // Check if the parameter is within the valid range
        if (parameter < 0 || parameter > 2) {
            System.out.println("Invalid parameter. Please provide a value between 0 and 2 (inclusive).");
            System.exit(1);
        }

	if (parameter == 0) {
        	// Let LLM know what we want:
        	String promtStart = "Generate a concise C file without unnecessary includes, but with output. The C file should be a standard program, but with a twist:"
                	+ " it replaces all constants in the main function with argument assignments, adds required includes.";
        	promtStart += "Example ```C\n#include <stdio.h>\n#include <stdlib.h>\nint main(int argc, char *argv[]) {\n"
                	+ "  if (argc != 2) {\n    printf(''Usage: %s <value>\n'', argv[0]);\n    return 1;\n  }\n  int x = atoi(argv[1]);\n"
                	+ "  return x - 4;\n}```\nDo you think you can do that?";
       		System.out.println(promtStart);
	} else if (parameter == 1) {
		// Set all objects we need
        	//ProgramGenerator compilerStrings = new ProgramGenerator();
        	LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();

            	// Get a random entry from each array
            	String randomCompilerOpt = llmIndexedTokens.getRandomCompilerOpt();
            	String randomCompilerParts = llmIndexedTokens.getRandomCompilerParts();
            	String randomPL = llmIndexedTokens.getRandomPL();

            	// program
            	String prompt = 
			"Coding task: give me a program in C with all includes. Input is taken via argv only. Please return a program (C program) and a concrete example of an input (BASH). " 
			+ "The C program will be with code triggering " + randomCompilerOpt + " optimizations, covers this part of the compiler "
                    	+ randomCompilerParts + ", and exercises this idea in C: " + randomPL + ". To recap the code contains these: " + randomCompilerOpt 
			+ " and " + randomCompilerParts + " and " + randomPL;
		System.out.println(prompt);
	} else {
	    String res = args[2];
	    if (res.isEmpty()) {
		System.out.println("Invalid parameter. Please provide a result text from LLM model.");
            	System.exit(1);
            }

	    // Create a parser
	    Parser parser = new Parser();

            // Program
            String program = parser.getCProgram(res);

            // Input
            String callLine = parser.getArgsInput(res);

            // Type
            String argsType = parser.getTypes(res, callLine);

	    // Print all
	    System.out.println(argsType);
	    System.out.println(callLine);
	    System.out.println(program);
	}
    }
}
