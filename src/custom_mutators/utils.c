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

/* ============================================= */
/* ============================================= */
/* ============================================= */
// File manipulation utils
/* ============================================= */
/* ============================================= */
/* ============================================= */

// extract path
void extractPath(const char *input, char *path) {
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
    char path[100];
    extractPath(input, path);
    char name[50];
    rand_name(name, sizeof(name));

    strcpy(bin, path);
    strcat(bin, "fuzz_");
    strcat(bin, name);
    strcat(bin, ".c.o");
    strcpy(type, bin);
    strcat(type, ".types");
}

// Copy files
int copyFile(const char *source, const char *destination) {
    char command[250] = "cp ";
    strcat(command, source);
    strcat(command, " ");
    strcat(command, destination);
    return system(command);
}

// Write a new file data
bool writeStringToFile(const char *data, const char *fileName) {
    // Open the file for writing (create if it doesn't exist)
    FILE *file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Write the data to the file
    size_t dataLength = strlen(data);
    size_t itemsWritten = fwrite(data, 1, dataLength, file);
    
    // Close the file
    fclose(file);

    // Return if succ
    return !(itemsWritten < dataLength);
}