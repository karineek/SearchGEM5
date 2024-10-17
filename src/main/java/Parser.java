/**
 * @file Parser.java
 *
 * @brief Parser for the output (answer) from LLM model into 3 files: C program,
 *	input example, and type file describing each of data type of the input.
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
import java.util.Random;
import java.util.regex.*;

class Parser {

    // Try to extract the code
    private String getCode(String input, String cCodeRegex) {
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

    // Try to get param
    private String getParams(String input) {
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

    // Try to eastimate max arguments
    private int getMaxArgvNumber(String input) {
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
    private String stringLeft(String input, String substring, int offset) {
        // Find the index of "./" in the input string
        int index = input.indexOf(substring);
        // If "./" is found, extract the substring after it
        return ((index != -1) && (index + offset < input.length())) ?
                input.substring(index + offset) : "";
    }

    private static String formatText(String inputText) {
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
	} else if (inputText.contains("```sh")) {
	    return "sh";
        } else {
            // Default case: return the original text
            return "";
        }
    }

    private  String determineType(String input) {
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

    private String getArgumentsTypes(String argsValue, int argsSize) {
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

    // C program extractor
    public String getCProgram(String res) {
        String CString = (res.contains("```c*") ? "```c*" : "```C*");
        return getCode(res, CString);
    }

    // Gets an example for the inpit for the C program
    public String getArgsInput(String res) {
        String bashForm = formatText(res);
        String inputCleaned = stringLeft(getCode(res, "```" + bashForm + "*"), "./", 2);
        if (inputCleaned.isEmpty()) {
            inputCleaned = getCode(res, "```\n" + bashForm + "./*");
            if (inputCleaned.isEmpty()) {
                inputCleaned = getCode(res, "```\n./*");
                if (inputCleaned.isEmpty()) {
                    inputCleaned = getCode(res, "`./*");
                }
            }
        }
        String[] lines = inputCleaned.split("`?\\r?\\n");
        String inputFirstLine = (lines.length == 0 ? inputCleaned : lines[0]);   // If not empty, but parsing failed, try to take the original results
        String callLine = (inputFirstLine.isEmpty()
			? "0"  // If empty, we failed getting input.
                    	: stringLeft(inputFirstLine, " ", 0));

        // Remove leading space
        callLine = callLine.trim();
        while (callLine.length() > 0 && callLine.charAt(0) == ' ') {
            callLine = callLine.substring(1);
        }
        return callLine;
    }

    // Type file extraction
    public String getTypes(String program, String callLine) {
        int maxArgs = getMaxArgvNumber(program);
        if (program.contains("argv[i]") || program.contains("argv[j]") || (maxArgs > 0)) {
            return getArgumentsTypes(callLine, maxArgs);
        } else {
            return "";
        }
    }
}
