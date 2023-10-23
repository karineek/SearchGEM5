/**
 * @file cm-gem5.c
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

#include "cm-gem5.h"
#include "utils.h"

// Compilation flags. Read the project README.md to understand how to use thses.
//#define DEBUG_CM 1                // Debug or afl plugin
//#define MUTATOR_BIN 1             // Mutator - binary file mutation only
//#define MUTATOR_ARGS 1            // Mutator - Arg mutation only
//#define MUTATOR_TYPE 1            // Mutator - Type of args mutation only
#define PROBABILITY_ARGS_FLIP 350   // Out of 1000
#define PROBABILITY_TYPE_FLIP 300   // Out of 1000


/* ============================================= */
/* ============================================= */
/* ============================================= */
// General AFL++ Interface functions
/* ============================================= */
/* ============================================= */
/* ============================================= */

#ifndef DEBUG_CM
extern AFL_RAND_RETURN rand_next(afl_state_t *afl);
#endif

/**
 * Initialize this custom mutator
 *
 * @param[in] afl a pointer to the internal state object. Can be ignored for
 * now.
 * @param[in] seed A seed for this mutator - the same seed should always mutate
 * in the same way.
 * @return Pointer to the data object this custom mutator instance should use.
 *         There may be multiple instances of this mutator in one afl-fuzz run!
 *         Return NULL on error.
 */
my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed) {

  srand(seed);  // needed also by surgical_havoc_mutate()

  my_mutator_t *data = calloc(1, sizeof(my_mutator_t));
  if (!data) {
    perror("afl_custom_init alloc");
    return NULL;
  }

  if ((data->out_buff = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  if ((data->file_name_types = (char *)malloc(MAX_FILE_NAME_SIZE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  if ((data->input_args = (char *)malloc(MAX_ARGS_SIZE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  if ((data->input_digit = (char *)malloc(MAX_DATA_SIZE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  data->afl = afl;

// Info. regarding the build
#ifdef MUTATOR_ARGS
    printf("MUTATOR_ARGS");
#else
#   ifdef MUTATOR_BIN
    printf("MUTATOR_BIN");
#   else
#       ifdef MUTATOR_TYPE
            printf("MUTATOR_TYPE");
#       else
            printf("ALL-MUTATORS");
#       endif // MUTATOR_TYPE
#   endif // MUTATOR_BIN
#endif // MUTATOR_ARGS

  return data;
}

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
void afl_custom_deinit(my_mutator_t *data) {
  data->afl = 0;
  free(data->out_buff);
  free(data->file_name_types);
  free(data->input_args);
  free(data->input_digit);
  free(data);
}

/**
 * Perform custom mutations on a given input
 *
 * (Optional for now. Required in the future)
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Pointer to input data to be mutated
 * @param[in] buf_size Size of input data
 * @param[out] out_buf the buffer we will work on. we can reuse *buf. NULL on
 * error.
 * @param[in] add_buf Buffer containing the additional test case
 * @param[in] add_buf_size Size of the additional test case
 * @param[in] max_size Maximum size of the mutated output. The mutation must not
 *     produce data larger than max_size.
 * @return Size of the mutated output.
 */
size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf, size_t buf_size,
                       u8 **out_buf, uint8_t *add_buf,
                       size_t add_buf_size,  // add_buf can be NULL
                       size_t max_size) {

    size_t new_size = MAX_CMDLINE_SIZE <= max_size ? MAX_CMDLINE_SIZE : max_size;
    if (new_size < buf_size) {
        WARNF("Max size of register is: %zu, %zu", new_size, buf_size);
        return 0; // We cannot work with this
    }

    // Allocate a new buffer for the edits
    uint8_t *new_buf = malloc(new_size);
    if (!new_buf) {
        WARNF("Bad allocation for buffer for mutations. Could not allocate %zu size buffer.", new_size);
        return 0;
    }

    // Copy the original input data
    memcpy(new_buf, buf, buf_size);


    // KEM: here we can define 3 mutators: combine one, args mutator and binary mutator.
#ifdef MUTATOR_ARGS
    // bit flip on the arguments
    findAndMutateArgs(new_buf, data);
#else
#   ifdef MUTATOR_BIN
    // mutate the binary
    mutateBinary(new_buf, data);
#   else
#       ifdef MUTATOR_TYPE
            mutateTypeData(new_buf, data);
#       else
            // Mutate!
            if (mutator_rand(data, 0, 1000, 0) < 995) {
                // bit flip on the arguments
                findAndMutateArgs(new_buf, data);
            } else {
                // mutate the binary
                mutateBinary(new_buf, data);
            }
            // Check if we mutated correctly
            if (!new_buf) {
                WARNF("Bad generation for buffer with mutations.");
                return 0;
            }
#       endif // MUTATOR_TYPE
#   endif // MUTATOR_BIN
#endif // MUTATOR_ARGS



    // Shrink the buffer till \0
    size_t actual_size = strlen(data->out_buff) + 1; // Add 1 for the null-terminator
    uint8_t *new_new_buf = malloc(actual_size);
    if ((!new_buf) || (!new_new_buf)) {
        WARNF("Bad re-allocation for buffer for mutations. Could not allocate %zu size buffer.", actual_size);
        return 0;
    }
    //printf("Size: %zu", actual_size);
    memcpy(new_new_buf, new_buf, actual_size);

    // Set it as output buff
    *out_buf = new_new_buf;

    // Clear the old data
    free(new_buf);

    return actual_size;
}

/* ================================================ */
/* ================================================ */
/* ================================================ */
// General Functions: read/write files and bit-flips
/* ================================================ */
/* ================================================ */
/* ================================================ */

// Read the types from file
void readTypes(my_mutator_t *data, char** buffer) {
    // Open the file for reading
    FILE *file = fopen(data->file_name_types, "r");
    if (file == NULL) {
        perror("Error opening file");
        buffer = 0;
        return;
    }

    // Allocate space
    if ((*buffer = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
        perror("afl buffer malloc failed");
        return;
    }

    // Read the file line by line
    if (fgets(*buffer, sizeof(*buffer), file) == NULL) {
        perror("Error reading file");
        buffer = 0;
        return;
    }
    char* tmp;
    // Allocate space
    if ((tmp = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
        perror("afl buffer malloc failed");
        return;
    }
    while (fgets(tmp, sizeof(tmp), file) != NULL) {
        strcat(*buffer,tmp);
    }
    free(tmp);

    // Close the file
    fclose(file);
}

// Random int generator - either len or rate used!
int mutator_rand(my_mutator_t *data, size_t len, int rate, long filesize) {
    if (rate == 0 && len == 0 && filesize == 0) return 0;
    if (!data) return 0;

#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    int num =
#ifndef DEBUG_CM
        (data->afl) ? rand_below(data->afl, (filesize == 0 ? (rate==0 ? len : rate) : filesize)) :
#endif
        rand() % (filesize == 0 ? (rate==0 ? len : rate) : filesize); // Random location in the register
    return num;
}

// Bit flip integer of 8 bits
void mutateUInt8Value(char *token, my_mutator_t *data, char* format) {
    if (!token) return;
    if (!data) return;
    if (!format) return;

    unsigned char num;
    if (sscanf(token, "%hhu", &num) == 1) {
        unsigned int bit_pos = ((num != (unsigned char)CHAR_MIN) && mutator_rand(data, 0, 1000, 0) < 50) ? (sizeof(unsigned char) * 8) - 1 // Sign flip
                :  mutator_rand(data, (sizeof(unsigned char) * 8), 0, 0); // Bit flip
        num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 16 bits
void mutateUInt16Value(char *token, my_mutator_t *data, char* format) {
    if (!token) return;
    if (!data) return;
    if (!format) return;

    unsigned short num;
    if (sscanf(token, "%hu", &num) == 1) {
        unsigned int bit_pos = ((num != (unsigned short)SHRT_MIN) && mutator_rand(data, 0, 1000, 0) < 10) ? (sizeof(unsigned short) * 8) - 1 // Sign flip
                : mutator_rand(data, (sizeof(unsigned short) * 8), 0, 0); // Bit flip
        num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 32 bits
void mutateUInt32Value(char *token, my_mutator_t *data, char* format) {
    if (!token) return;
    if (!data) return;
    if (!format) return;

    unsigned int num;
    if (sscanf(token, "%u", &num) == 1) {
        unsigned int bit_pos = ((num != (unsigned int)INT_MIN) && mutator_rand(data, 0, 1000, 0) < 20) ? (sizeof(unsigned int) * 8) - 1 // Sign flip
                : mutator_rand(data, (sizeof(unsigned int) * 8), 0, 0); // Bit flip
	    num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 64 bits
void mutateUInt64Value(char *token, my_mutator_t *data, char* format) {
    if (!token) return;
    if (!data) return;
    if (!format) return;

    unsigned long num;
    if (sscanf(token, "%lu", &num) == 1) {
        unsigned int bit_pos = ((num != (unsigned long)LONG_MIN) && mutator_rand(data, 0, 1000, 0) < 30) ? (sizeof(unsigned long) * 8) - 1 // Sign flip
		: mutator_rand(data, (sizeof(unsigned long) * 8), 0, 0); // Bit flip
        num ^= (1ul << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Float bit flip
void mutateFloatValue(char *token, my_mutator_t *data) {
    if (!token) return;
    if (!data) return;

    float num;
    unsigned int int_repr;
    if (sscanf(token, "%f", &num) == 1) {
	    // Flip bit
        memcpy(&int_repr, &num, sizeof(float)); // dump to uint
        unsigned int bit_pos = mutator_rand(data, (sizeof(unsigned int) * 8), 0, 0);
        int_repr ^= (1u << bit_pos); // Bit flip it
        memcpy(&num, &int_repr, sizeof(float)); // back to float
        sprintf(token, "%f", num); // Copy it back
    }
}

// Double bit flip
void mutateDoubleValue(char *token, my_mutator_t *data) {
    if (!token) return;
    if (!data) return;

    double num;
    unsigned long int_repr;
    if (sscanf(token, "%lf", &num) == 1) {
        // Flip bit
        memcpy(&int_repr, &num, sizeof(double)); // dump to uint
        int bit_pos = mutator_rand(data, (sizeof(unsigned long) * 8), 0, 0);
        int_repr ^= (1ul << bit_pos); // Bit flip it
        memcpy(&num, &int_repr, sizeof(double)); // back to float
        sprintf(token, "%lf", num); // Copy it back
    }
}

// String bit flip
void mutateStringValue(char *token, my_mutator_t *data) {
    if (!token) return;
    if (!data) return;

    unsigned int pos = mutator_rand(data, strlen(token), 0, 0);
    char* mutate_buf = malloc(MAX_DATA_SIZE);
    if (!mutate_buf) return;

    // Else continue with the mutation
    sprintf(mutate_buf, "%hhd", (int8_t) token[pos]); // Copy it back
    mutateUInt8Value(mutate_buf,data,"%hhd");

    int integerValue = atoi(mutate_buf); // Convert string to integer
    token[pos] = (char)integerValue; // Convert integer to char

    free(mutate_buf);
}

// Prepare data before mutation
void initCurrentMutationData(uint8_t *new_buf, my_mutator_t *data, int is2add_new_line) {
    // Init buffers
    data->out_buff[0] = '\0';
    data->file_name_types[0] = '\0';
    data->input_args[0] = '\0';

    char *token = strtok((char *)new_buf, "\n");    // Split lines
    if (!token) return; // Leter all data fields is empty so the process should terminate gracefully

    // Else continue with the init
    strcpy(data->out_buff,token);                   // Keep the name of the binary
    if (is2add_new_line)
        strncat(data->out_buff, "\n", 1);           // Add back the newline
    strcpy(data->file_name_types, token);           // Keep the file name
    strncat(data->file_name_types, ".types", 6);    // Add back the .types ending

    // Add the args lines again
    token = strtok(NULL, "\n");
    if (token != NULL) {
       strcpy(data->input_args, token);
    }
}

// Check if the args are only 1.
bool is_one_arg_call(char *str) {
    if (!str) return true; // empty string means no tokens - true

    const char *pos = str;
    int count = 0;
    if (str[0] != ' ') count = -1;

    while ((pos = strchr(pos, ' ')) != NULL) {
        count++;
        pos++; // Move to the next character position
    }
    return (count < 2); // BiNARY INT => 1 space and 1 args.
}

// Function to generate a random new_type_token
const char* generateRandomTypeToken() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and 2
    int randomValue = rand() % 11;

    // Define the possible type tokens
    const char* typeTokens[] = {"UINT32", "INT32", 
                "ULONG", "LONG", "USHORT", "SHORT", 
                "UCHAR", "CHAR", "FLOAT", "DOUBLE",
                "STRING"};

    // Return the randomly selected type token
    return typeTokens[randomValue];
}

/* ============================================= */
/* ============================================= */
/* ============================================= */
// MUTATORS
/* ============================================= */
/* ============================================= */
/* ============================================= */

// Mutate arguments for the binary in the corpus: the input data
void findAndMutateArgs(uint8_t *new_buf, my_mutator_t *data) {
    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 1);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { new_buf=0; return; }		        // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { new_buf=0; return; } 		            // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { new_buf=0; return; }    // t.c.o.types - cannot be smaller

    // Space for temporary manipulations
    char* types_token = 0;
    char* buf_token = 0;
    char *saveptr1=0;
    char *saveptr2=0;

    // Read tokens of data types
    char *token = strtok_r(data->input_args, " ", &saveptr1);
    readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
    if (!invalid_tokens) {
	    types_token = strtok_r(buf_token, " ", &saveptr2);
        if ((types_token != NULL) && (strcmp(types_token,"BINARY") == 0)) {
	        types_token = strtok_r(NULL, " ", &saveptr2); // Next type token, we don't mutate here the binary (differnt mutation)
	    }
    }

    // Find numeric parts and mutate them using mutateNumericValue function
    bool is_many_args = !is_one_arg_call(buf_token);
    while (token != NULL) {
        // TODO: add a rand to sometimes skip mutation
    	data->input_digit[0] = '\0';
    	strcpy(data->input_digit, token);

	    // TODO: Nasty mutation

        if ((is_many_args) && (mutator_rand(data, 0, 1000, 0) < PROBABILITY_ARGS_FLIP))
            is_many_args = false; // Just skip one replace
        else if (invalid_tokens)
    	    mutateUInt32Value(data->input_digit, data, "%u");
	    else {
            // In this for specific identified data types
            if (strcmp(types_token,"UINT32") == 0)
                mutateUInt32Value(data->input_digit, data, "%u");
            else if (strcmp(types_token,"INT32") == 0)
                mutateUInt32Value(data->input_digit, data, "%d");
            else if (strcmp(types_token,"ULONG") == 0)
                mutateUInt64Value(data->input_digit, data, "%lu");
            else if (strcmp(types_token,"LONG") == 0)
                mutateUInt64Value(data->input_digit, data, "%ld");
            else if (strcmp(types_token,"USHORT") == 0)
                mutateUInt16Value(data->input_digit, data, "%hu");
            else if (strcmp(types_token,"SHORT") == 0)
                mutateUInt16Value(data->input_digit, data, "%hd");
            else if (strcmp(types_token,"UCHAR") == 0)
                mutateUInt16Value(data->input_digit, data, "%hhu");
            else if (strcmp(types_token,"CHAR") == 0)
                mutateUInt16Value(data->input_digit, data, "%hhd");
            else if (strcmp(types_token,"FLOAT") == 0)
                mutateFloatValue(data->input_digit, data);
            else if (strcmp(types_token,"DOUBLE") == 0)
                mutateFloatValue(data->input_digit, data);
            else if (strcmp(types_token,"STRING") == 0)
                mutateStringValue(data->input_digit, data);
            else
                mutateUInt32Value(data->input_digit, data, "%u");
        }

        // Append the mutated string:
        size_t len = strlen(data->input_digit);
        size_t len_all = strlen(data->out_buff);
        if ((len + len_all) < (MAX_CMDLINE_SIZE - 1))
            strcat(data->out_buff, data->input_digit);

        // Next iteration:
	    token = strtok_r(NULL, " ", &saveptr1); // Next token
        if (token != NULL) strncat(data->out_buff, " ", 1); // add back the space
        if (!invalid_tokens && types_token != NULL) types_token = strtok_r(NULL, " ", &saveptr2); // Next type token
   }
   strcpy((char *)new_buf, data->out_buff);
}// End of findAndMutateArgs

// Mutate the binary
void mutateBinary(uint8_t *new_buf, my_mutator_t *data) {
    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 0);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { new_buf=0; return; }              // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { new_buf=0; return; }                   // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { new_buf=0; return; }    // t.c.o.types - cannot be smaller

    // Read tokens of data types
    char *buf_token = 0;
    readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
    if (invalid_tokens) return; // Cannot mutate

    // Create a new binary to mutate
    char bin_filename[100];
    char type_filename[100];
    generat_new_file_names(data->out_buff, bin_filename, type_filename);
    copyFile(data->file_name_types, type_filename);
    copyFile(data->out_buff, bin_filename);

    // Crete the mutated string to give back to AFL
    strcpy(data->out_buff, bin_filename);
    strcat(data->out_buff, "\n");
    strcat(data->out_buff, data->input_args);

    // How many to flip?
    int n = mutator_rand(data, 0, 10, 0);

    // TODO: improve efficiency
    for (int i=0; i < n; i++) {
        // Mutate!
        FILE *file = fopen(bin_filename, "rb+");
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        // Determine the size of the file
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        // Generate random byte index and bit position
        long byte_index = mutator_rand(data, 0, 8, file_size);
        int bit_position = mutator_rand(data, 0, 8, 0);

        // Read the byte at the chosen index
        fseek(file, byte_index, SEEK_SET);
        unsigned char byte;
        size_t items_read = fread(&byte, sizeof(byte), 1, file);
        if (items_read == 1) {
            // Flip the selected bit
            byte ^= (1u << bit_position);

            // Write the modified byte back to the file
            fseek(file, byte_index, SEEK_SET);
            fwrite(&byte, sizeof(byte), 1, file);

#ifdef TEST_CM
            printf("Bit at byte %ld, position %d flipped.\n", byte_index, bit_position);
#endif
        }

        fclose(file);
    }

    strcpy((char *)new_buf, data->out_buff);
    return;
} // End of mutateBinary


// Mutate the type data
void mutateTypeData(uint8_t *new_buf, my_mutator_t *data) {
    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 1);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { new_buf=0; return; }		        // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { new_buf=0; return; } 		            // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { new_buf=0; return; }    // t.c.o.types - cannot be smaller

    // Flag - if any type flipped?
    bool is_type_flipped = false;

    // Space for temporary manipulations
    char* types_token = 0;
    char* buf_token = 0;
    char *saveptr2=0;
    char type_newbuff[MAX_ARGS_SIZE];

    // Read tokens of data types
    readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
    if (!invalid_tokens) {
	    types_token = strtok_r(buf_token, " ", &saveptr2);
        if ((types_token != NULL) && (strcmp(types_token,"BINARY") == 0)) {
	        types_token = strtok_r(NULL, " ", &saveptr2); // Next type token, we don't mutate here the binary (differnt mutation)
            strcpy(type_newbuff, "BINARY"); 
	    } else {
            // Exit - we don't have enough information to continue this mutation
            new_buf=0; return; 
        }
    } else {
        // Exit - we don't have enough information to continue this mutation
        new_buf=0; return;
    }

    // Try to flip:
    bool is_many_args = !is_one_arg_call(buf_token);    // Check if a single parameter call
    buf_token = 0;
    while (types_token != NULL) {   // Format: BINARY STRING STRING
        // Rand a new type:
        const char* new_type_token = generateRandomTypeToken();

        // Prepare to add the next token
        strcat(type_newbuff, " ");

        // Check if we flipped the type
        if (strcmp(types_token,new_type_token) == 0) {
            // take it if !is_many_args otherwise consider it with some probablity
            if ((!is_many_args) || (mutator_rand(data, 0, 1000, 0) < PROBABILITY_TYPE_FLIP)) {
                // Replace to the mutated token
                strcat(type_newbuff, new_type_token);

                // set is_type_flipped to true
                is_type_flipped = true;
            } else {
                // Keep the original token
                strcat(type_newbuff, types_token);
            }
        } else {
            // Keep the original token
            strcat(type_newbuff, types_token);
        }

        types_token = strtok_r(NULL, " ", &saveptr2); // Next type token
    }

    // If flipped - then copy to a new set of mutated test case
    if (is_type_flipped) {
        // Create a new binary to mutate
        char bin_filename[100];
        char type_filename[100];

        generat_new_file_names(data->out_buff, bin_filename, type_filename);
        if (writeStringToFile(type_newbuff,type_filename)) {
            copyFile(data->out_buff, bin_filename);

            // Crete the mutated string to give back to AFL
            strcpy(data->out_buff, bin_filename);
            strcat(data->out_buff, "\n");
            strcat(data->out_buff, data->input_args);

            // Copy the new mutated string to give to AFL
            strcpy((char *)new_buf, data->out_buff);
	} else {
	    // failed to generate a new type file - exit
	    new_buf=0;
	}
    } else {
        // If no mutation - exit with buffer null.
        new_buf=0;
    }
    return;
}
