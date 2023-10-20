/**
 * @file cm-gem5.h
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

#ifndef CUSTOM_MUTATOR_H
#define CUSTOM_MUTATOR_H

#include "afl-fuzz.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <limits.h>

typedef struct my_mutator {

  afl_state_t *afl;

  char* out_buff; // The whole args in buffers

  char* file_name_types; // The name of the file with types to mutate

  char* input_args; // Keeps the input arguments for mutating

  char* input_digit; // Buffer for register mutations

} my_mutator_t;

// Size of buffers used during mutation
#define MAX_CMDLINE_SIZE (250)
#define MAX_FILE_NAME_SIZE (100)
#define MAX_ARGS_SIZE (140)
#define MAX_DATA_SIZE (45)

// AFL++ Interface functions
my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed);
size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf, size_t buf_size,
                       u8 **out_buf, uint8_t *add_buf,
                       size_t add_buf_size,  // add_buf can be NULL
                       size_t max_size);
void afl_custom_deinit(my_mutator_t *data);

// Mutator - Main function
void findAndMutateArgs  (uint8_t *new_buf, my_mutator_t *data); 
void mutateBinary       (uint8_t *new_buf, my_mutator_t *data);
void mutateTypeData     (uint8_t *new_buf, my_mutator_t *data);

// Mutator functions - helpers
void mutateUInt8Value   (char *token, my_mutator_t *data, char* format);
void mutateUInt16Value  (char *token, my_mutator_t *data, char* format);
void mutateUInt32Value  (char *token, my_mutator_t *data, char* format); 
void mutateUInt64Value  (char *token, my_mutator_t *data, char* format);
void mutateFloatValue   (char *token, my_mutator_t *data);
void mutateDoubleValue  (char *token, my_mutator_t *data);
void mutateStringValue  (char *token, my_mutator_t *data);

void readTypes(my_mutator_t *data, char** buffer);
int  mutator_rand(my_mutator_t *data, size_t len, int rate, long filesize);
void initCurrentMutationData(uint8_t *new_buf, my_mutator_t *data, int is2add_new_line);
bool is_one_arg_call(char *str);
const char* generateRandomTypeToken();

#endif // CUSTOM_MUTATOR_H