/**
 * @file utils.c
 *
 * @brief The file is a set of AFL++ mutators for gem5 binary test cases used
 *        in SearchGem5. The project is AFL++-basd. Please include AFL++ 
 *        headers and download the recent version before running this code.
 *        You need to use -I/path/to/AFLplusplus/include -I.
 *
 * For more details on the AFL++ API used in this project, please refer to:
 * - AFL++: https://github.com/AFLplusplus/AFLplusplus
 *
 *
 * @copyright (C) 2023, Aidan Dakhama, Karine Even-Mendoza, William B. Langdon, 
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

#include "utils.h"

#include <time.h>   // For struct timespec and clock_gettime
#include <string.h> // For strchr, strrchr, strncpy, and strcat
#include <stdlib.h> // For system(command) call
#include <stdio.h>  // File ops.

// Include for testing output before sending to AFL++
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* ============================================= */
/* ============================================= */
/* ============================================= */
// File manipulation utils
/* ============================================= */
/* ============================================= */
/* ============================================= */

// extract path
void extractPath(const char *input, char *path) {
    if (!input) return; // check we got input

    // Find the last occurrence of '/'
    const char *lastSlash = strrchr(input, '/');
    if (lastSlash != NULL) {
        strncpy(path, input, lastSlash - input + 1);
        path[lastSlash - input + 1] = '\0';
    }
}

// Get random name:
void rand_name(char *timestampString, size_t bufferSize) {
    struct timespec currentTime;
    clock_gettime(CLOCK_REALTIME, &currentTime);
    snprintf(timestampString, bufferSize, "%ld%ld", currentTime.tv_sec, currentTime.tv_nsec);
}

// Rename file so we can muate the binary
void generat_new_file_names(char *input, char *bin, char *type) {
    if (!input) return; // check we got input

    char path[100];
    extractPath(input, path);
    if (strlen(path) < 5) return; // Probably not a valid path - too short

    // Generate random number for unique name
    char name[50];
    rand_name(name, sizeof(name));

    // Copy the name
    strcpy(bin, path);
    strcat(bin, "fuzz_");
    strcat(bin, name);
    strcat(bin, ".c.o");
    strcpy(type, bin);
    strcat(type, ".types");
}

// Writes to logger
#ifdef TEST_CM
bool writeToLogFile(const char *logFile, const char *msg) {
    if (!logFile) return false; // Check we have a  file name

    // try to open logFile
    FILE *file = fopen(logFile, "a");
    if (file == NULL) {
        perror("Error opening log file");
        return false;
    }

    // Write the message to the log file
    fprintf(file, "%s\n", msg);

    // Close the file
    fclose(file);

    return true;
}
#endif

// Copy files
int copyFile(const char *source, const char *destination) {
#ifdef TEST_CM
    writeToLogFile("afl_log.log", "====== Try to write file");
#endif

    // Check that both are not null
    if (source == NULL) return -1; // Command failed due to bad names
    if (destination == NULL) return -1; // Command failed due to bad names
    if (source[0] == '\0') return -1; // Command failed: file name is empty
    if (destination[0] == '\0') return -1; // Command failed: file name is empty
    if (strlen(source) < 3) return -1; // Command failed: file name is too short
    if (strlen(destination) < 3) return -1; // Command failed: file name is too short

    char command[250] = "cp ";
    strcat(command, source);
    strcat(command, " ");
    strcat(command, destination);

#ifdef TEST_CM
    writeToLogFile("afl_log.log", command);
#endif

    return system(command);
}

// Write a new file data
bool writeStringToFile(const char *data, const char *fileName) {
    // Check if inputs are valid:
    if (fileName == NULL) return 0; // Command failed due to bad names
    if (fileName[0] == '\0') return 0; // Command failed: file name is empty
    if (strlen(fileName) < 3) return 0; // Command failed: file name is too short
    if (data == NULL) return 0; // Command failed due to no data
    if (data[0] == '\0') return 0; // Command failed due to empty

    // Open the file for writing (create if it doesn't exist)
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
#ifdef TEST_CM
        print_error(">>-16-A Error opening file for writing", fileName);
#endif
        return 0;
    }

    // Write the data to the file
    int charsWritten = fprintf(file, "%s\n", data);

    // Close the file
    fclose(file);

    // Return if succ
    if ((charsWritten < 0) || (charsWritten != strlen(data))) {
#ifdef TEST_CM
        print_error(">>-16-B Error writing to file", fileName);
#endif
        return 0;
    } else {
    	return 1;
    }
}

// Print error message via perror with additinal information
void print_error(const char *msg, const char *data) {
    if ((msg == NULL) || (data == NULL)) {
	if (msg != NULL) {
	     perror(msg);
        } else if (data != NULL) {
    	     perror(data);
	} else {
	     perror(">>-17 Unkown error, both msg and data information are misisng");
        }
    } else { // We have both
	char error_message[300];  // Adjust the size as needed
        sprintf(error_message, "%s (%s)", msg, data);
	perror(error_message);
    }
}

// Count the number of lines in a buffer to check no bad mutations written
int countLines(const char *str) {
    if (str == NULL) return 0;

    int lineCount = 0;
    size_t length = strlen(str);

    for (size_t i = 0; i < length; ++i) {
        if (str[i] == '\n') {
            lineCount++;
        }
    }
    return lineCount+1;
}

// Test if the test should go into AFL++ - seg fault crashes AFL++
int isTestInputValid(const char *input) {
    char inputCopy[250];  // Adjust the size as needed
    strcpy(inputCopy, input);

    char* binaryPath = strtok(inputCopy, "\n");   // first string
    char* argument = strtok(NULL, "\n");  // second string

#ifdef TEST_CM
    writeToLogFile("afl_log.log", "==== IN CHECK OF VALID TEST ====");
    writeToLogFile("afl_log.log", input);
    if (!binaryPath || !argument) {
	return 0; // Invalid input
    }
    writeToLogFile("afl_log.log", binaryPath);
    writeToLogFile("afl_log.log", argument);
#else
    if (!binaryPath || !argument) {
        return 0; // Invalid input
    }
#endif

    // Start the test
    pid_t childPid = fork();
    if (childPid == -1) {
        return 0; // failed - cannot test
    }

    if (childPid == 0) {
	bool failed = (freopen("/dev/null", "w", stdout) == NULL) ||
		   (freopen("/dev/null", "w", stderr) == NULL);

        // Child process
        execlp(binaryPath, binaryPath, argument, NULL);
        return !failed;
    } else {
        // Parent process
        int status;
        waitpid(childPid, &status, 0);

        if (WIFSIGNALED(status)) {
            // Check if the signal is either SIGSEGV (segmentation fault)
            return !(WTERMSIG(status) == SIGSEGV);
        }
        return 1; // If never got error, return 1
    }
}

/*
int main() {
    const char *binaryPath1 = "/home/ubuntu/experiment-7/gpt3.5-old/binary/ssad-run.c.o\n0";
    const char *binaryPath2 = "/home/ubuntu/experiment-7/gpt3.5-old/binary/ssad-run.c.o\n65536";

    int result = isTestInputValid(binaryPath1);
    if (result == 1) {
        printf("Binary exited normally.\n");
    } else if (result == 1) {
        printf("Binary terminated by segmentation fault.\n");
    } else {
        printf("Unknown exit status.\n");
    }

    result = isTestInputValid(binaryPath2);
    if (result == 1) {
        printf("Binary exited normally.\n");
    } else if (result == 0) {
        printf("Binary terminated by segmentation fault.\n");
    } else {
        printf("Unknown exit status.\n");
    }

    return 0;
}
*/
