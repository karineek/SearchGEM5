/**
 * @file TestInputWriter.java
 *
 * @brief The TestInputWriter class facilitates the creation of test input files for gem5 testing with afl++,
 * automating the process of generating C code, compiling it, and creating input files for gem5 testing.
 *
 *
 * @copyright (C) 2023,2024 Aidan Dakhama, Karine Even-Mendoza, William B. Langdon, 
 *                      Hector D. Menendez, Justyna Petke.
 *                King's College London and UCL University College London.
 *
 * This C file is part of SearchGem5 Project.
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

import java.util.Random;
import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.nio.charset.StandardCharsets;

class TestInputWriter {
    private static final Random random = new Random();

    private static String generateFilename(String prefix) {
        return prefix + System.nanoTime() + ".c";
    }

    private boolean writeFile(String filename, String content) {
        // Writing content to the specified file
        try {
            // Using java.nio.file to write to the file
            byte[] contentBytes = content.getBytes(StandardCharsets.UTF_8);
            Files.write(Path.of(filename), contentBytes, StandardOpenOption.CREATE, StandardOpenOption.WRITE);
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
            return false;
        }
        return true;
    }

    // input_test_bit_binary : inpupt_test_bit
    private boolean generateBinary(String filename, String objName) {
        try {
            String[] compilationCommand = {"gcc", "-O3", filename, "-o", objName};
            ProcessBuilder processBuilder = new ProcessBuilder(compilationCommand);
            processBuilder.redirectErrorStream(true);
            Process process = processBuilder.start();
            return (0 == process.waitFor());
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean writeTest(String program, String callLine, String argsType) {
	// If missing data - exit.
      	if (argsType.isEmpty() || callLine.isEmpty() || program.isEmpty()) {
        	System.out.println(">>> Bad program. Skip this test input.");
		return false;
	}

	// Try to write the test
	String fileNameC = generateFilename("test_input_");
	String fileNameObj = fileNameC + ".o";
	String fileNameType = fileNameC + ".type";
	String fileNameInput = fileNameC + ".txt";

	// Try to write the C program as a file
    	if (!writeFile(fileNameC, program)) {
		System.out.println("File Write Failed: program");
		return false;
	}

	// Try to generate the binary
	if (!generateBinary(fileNameC, fileNameObj)) {
		System.out.println("File Write Failed: Binary");
		return false;
	}

	// Try to write the Input test (as we will give it to gem5)
	String testArgs = fileNameObj + "\n" + callLine;
        if (!writeFile(fileNameInput, testArgs)) {
		System.out.println("File Write Failed: Fuzz data");
		return false;
	}

      	// Try to write the type file
     	if (!writeFile(fileNameType, argsType)) {
		System.out.println("File Write Failed: Type");
		return false;
	}
        return true;
    }
}
