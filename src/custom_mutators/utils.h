/**
 * @file utils.h
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

#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdbool.h>

// Extract path from input
void extractPath(const char *input, char *path);

// Get a random name
void rand_name(char *timestampString, size_t bufferSize);

// Generate new file names for binary and type
void generat_new_file_names(char *input, char *bin, char *type);

// Writes to logger instead into perror or stdout
#ifdef TEST_CM
bool writeToLogFile(const char *logFile, const char *msg);
#endif

// Copy files from source to destination
int copyFile(const char *source, const char *destination);

// Write file data
bool writeStringToFile(const char *data, const char *fileName);

// Print error message to screen
void print_error(const char *msg, const char *data);

// Count the number of lines in a buffer to check no bad mutations written
int countLines(const char *str);

// Test Before Sending to AFL++
int isTestInputValid(const char *input);

#endif // UTILS_H
