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

#include "cm-gem5.h"
#include "utils.h"

// Compilation flags. Read the project README.md to understand how to use thses.
//#define DEBUG_CM 1                // Debug or afl plugin
//#define MUTATOR_BIN 1             // Mutator - binary file mutation only
//#define MUTATOR_ARGS 1            // Mutator - Arg mutation only
//#define MUTATOR_TYPE 1            // Mutator - Type of args mutation only

//#define USE_CUSTOM_FUZZ_COUNT 1   // Override custom count fuzz function
//#define COUNTER_ALL 1             // for the value the function return counter fuzz - for the general custom mutator
//#define COUNTER_BIN 1             // Same as above but for binary mutator
//#define COUNTER_ARGS 1            // Same as above but for argument mutator
//#define COUNTER_TYPE 1            // Same as above but for type mutator
//#define SAVE_ALL 0                // Save all fuzzed corpus

#define PROBABILITY_ARGS_FLIP 350   // Out of 1000
#define PROBABILITY_TYPE_FLIP 300   // Out of 1000


/* ============================================= */
/* ============================================= */
/* ============================================= */
// General AFL++ Interface functions
/* ============================================= */
/* ============================================= */
/* ============================================= */

//#define DEBUG_CM 1 // To run debug with special main
//#define TEST_CM 1 // To run test with AFL++

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
    perror(">>-1 afl_custom_init alloc");
    return NULL;
  }

  if ((data->out_buff = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
    perror(">>-2 afl_custom_init malloc");
    return NULL;
  }

  if ((data->file_name_types = (char *)malloc(MAX_FILE_NAME_SIZE)) == NULL) {
    perror(">>-3 afl_custom_init malloc");
    return NULL;
  }

  if ((data->input_args = (char *)malloc(MAX_ARGS_SIZE)) == NULL) {
    perror(">>-4 afl_custom_init malloc");
    return NULL;
  }

  if ((data->input_digit = (char *)malloc(MAX_DATA_SIZE)) == NULL) {
    perror(">>-5 afl_custom_init malloc");
    return NULL;
  }

  data->afl = afl;

// TEST prints
#ifdef TEST_CM
// Info. regarding the build
#ifdef MUTATOR_ARGS
    printf(">> =MUTATOR_ARGS= ");
#else
#   ifdef MUTATOR_BIN
    printf(">> =MUTATOR_BIN= ");
#   else
#       ifdef MUTATOR_TYPE
            printf(">> =MUTATOR_TYPE= ");
#       else
            printf(">> =ALL-MUTATORS= ");
#       endif // MUTATOR_TYPE
#   endif // MUTATOR_BIN
#endif // MUTATOR_ARGS
#endif // End of TEST prints

  return data;
}

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
void afl_custom_deinit(my_mutator_t *data) {
  // Check if data is not nullptr
  if (!data) {
	  return; // nothing to do here
  } else {
    // Free out buffer if it is not nullptr
    if (data->out_buff != NULL) {
      free(data->out_buff);
    }

    // Free data->file_name_types if it is not nullptr
    if (data->file_name_types != NULL) {
      free(data->file_name_types);
    }

    // Free data->input_args if it is not nullptr
    if (data->input_args != NULL) {
      free(data->input_args);
    }

    // Free data->input_digit if it is not nullptr
    if (data->input_digit != NULL) {
      free(data->input_digit);
    }

    // Reset afl variable if needed
    data->afl = 0;

    // Free the main structure (data)
    free(data);
  }
}

#ifdef USE_CUSTOM_FUZZ_COUNT
// This function has various effects adding dependency on test input randominsation
unsigned int afl_custom_fuzz_count(void *data, const unsigned char *buf, size_t buf_size) {
#ifdef MUTATOR_ARGS
    return COUNTER_ARGS;
#else
#   ifdef MUTATOR_BIN
        return COUNTER_BIN;
#   else
#       ifdef MUTATOR_TYPE
            return COUNTER_TYPE;
#       else
            return COUNTER_ALL;
#       endif // MUTATOR_TYPE
#   endif // MUTATOR_BIN
#endif // MUTATOR_ARGS
}
#endif

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
        WARNF(">>-6 Max size of register is: %zu, %zu", new_size, buf_size);
        return 0; // We cannot work with this
    }

    // Allocate a new buffer for the edits
    uint8_t *new_buf = malloc(new_size);
    if (!new_buf) {
        WARNF(">>-7 Bad allocation for buffer for mutations. Could not allocate %zu size buffer.", new_size);
        return 0;
    }

    // Copy the original input data
    memcpy(new_buf, buf, buf_size);


    // KEM: here we can define 3 mutators: combine one, args mutator and binary mutator.
    bool mutations_rc = 0; // RC if mutations succ.
#ifdef MUTATOR_ARGS
    // bit flip on the arguments
    mutations_rc = findAndMutateArgs(new_buf, data);
#else
#   ifdef MUTATOR_BIN
    // mutate the binary
    mutations_rc = mutateBinary(new_buf, data);
#   else
#       ifdef MUTATOR_TYPE
            mutations_rc = mutateTypeData(new_buf, data);
#       else
            // Mutate!
            if (mutator_rand(data, 0, 1000, 0) < 995) {
                // bit flip on the arguments
                mutations_rc = findAndMutateArgs(new_buf, data);
            } else {
                // mutate the binary
                mutations_rc = mutateBinary(new_buf, data);
            }
#       endif // MUTATOR_TYPE
#   endif // MUTATOR_BIN
#endif // MUTATOR_ARGS

    // Check if no buff returned
    if (!new_buf) {
#ifdef TEST_CM
        WARNF(">>-8-A Bad generation for buffer with mutations.");
#endif
        return 0;
    }

#ifdef TEST_CM
    // Log the time
    static char timeString[30]; // Adjust the size according to your needs
    time_t currentTime;
    struct tm *localTime;

    // Get current time
    time(&currentTime);
    localTime = localtime(&currentTime);

    // Format time as a string
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localTime);
    writeToLogFile("afl_log.log",(const char *) timeString);

    // Print the buffer
    writeToLogFile("afl_log.log", "New buffer is this ===>");
    writeToLogFile("afl_log.log",(const char *) new_buf);
#endif

    // Check if mutation succ. and Check new_buf before declaring the mutation is okay
    if ((mutations_rc==0) || (countLines((const char *) new_buf) < 2)) {
#ifdef TEST_CM
        WARNF(">>-8-B Bad generation for buffer with mutations. Memory corrupted.");
        writeToLogFile("afl_log.log", ">>-8-B Bad generation for buffer with mutations. Memory corrupted.");
#endif
        free(new_buf);
	return 0;
    } // Else continue with the mutations


// This is too conservative - even after adding timeout handling, as it will miss many legit errors
    // Check if the test case ends with seg-fault and if so, return 0
//    if (!isTestInputValid((const char *) new_buf)) {
//#ifdef TEST_CM
//       writeToLogFile("afl_log.log", ">>-8-C Bad generation. Corrupted test input.");
//       writeToLogFile("afl_log.log",(const char *) new_buf);
//#endif
//       free(new_buf);
//       return 0;
//    }

#ifdef SAVE_ALL
    // Write the test before exit
    writeTestInputExternal((const char *) new_buf);
#endif

    // Shrink the buffer till \0
    size_t actual_size = strlen(data->out_buff) + 1; // Add 1 for the null-terminator
    uint8_t *new_new_buf = malloc(actual_size);
    if ((!new_new_buf)) {
        WARNF(">>-9 Bad re-allocation for buffer for mutations. Could not allocate %zu size buffer.", actual_size);
        return 0;
    }
    memcpy(new_new_buf, new_buf, actual_size);
    // Clear the old data
    free(new_buf);

    // Set it as output buff
    *out_buf = new_new_buf;

    // Return mutated
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
bool readTypes(my_mutator_t *data, char** buffer) {
    // Open the file for reading
    FILE *file = fopen(data->file_name_types, "r");
    if (file == NULL) {
        print_error(">>-10 Error opening file type", data->file_name_types);
        buffer = 0;
        return false;
    }

    // Allocate space
    if ((*buffer = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
        perror(">>-11 afl buffer malloc failed");
        return false;
    }

    // Read the file line by line
    if (fgets(*buffer, sizeof(*buffer), file) == NULL) {
        perror(">>-12 Error reading file");
        buffer = 0;
        return false;
    }
    char* tmp;
    // Allocate space
    if ((tmp = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
        perror(">>-13 afl buffer malloc failed");
        return false;
    }
    while (fgets(tmp, sizeof(tmp), file) != NULL) {
        strcat(*buffer,tmp);
    }
    free(tmp);

    // Close the file
    fclose(file);
    return true;
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
bool findAndMutateArgs(uint8_t *new_buf, my_mutator_t *data) {
#ifdef TEST_CM
    writeToLogFile("afl_log.log", "============================================= ARGS: try new loop ===>");
    writeToLogFile("afl_log.log", (char *) new_buf);
#endif

    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 1);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { return 0; }		   // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { return 0; } 		   // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { return 0; }    // t.c.o.types - cannot be smaller

    // Space for temporary manipulations
    char* types_token = 0;
    char* buf_token = 0;
    char *saveptr1=0; // Data
    char *saveptr2=0; // Type

    // Read tokens of data types
    bool rc_types = readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
    if (!invalid_tokens) {
	if (!haveSameNumberOfSpaces(buf_token, data->input_args,-1,0)) {
        	invalid_tokens=1; // We have mis match between number of parameters and types
#ifdef TEST_CM
		writeToLogFile("afl_log.log", ">> Not the same ARGS size");
#endif
	}
#ifdef TEST_CM
    	writeToLogFile("afl_log.log", data->input_args);
    	writeToLogFile("afl_log.log", buf_token);
#endif
    }

    // Start parsing the type list if valid
    if ((!invalid_tokens) && (rc_types)) {
	types_token = strtok_r(buf_token, " ", &saveptr2);
        if ((types_token != NULL) && (strcmp(types_token,"BINARY") == 0)) {
	    types_token = strtok_r(NULL, " ", &saveptr2); // Next type token, we don't mutate here the binary (differnt mutation)
	} else { return 0; }
    } else { invalid_tokens = 1; } // Invalid, we can now be a bit risky, and parse it as string (if many) or single (if one)

    // Find numeric parts and mutate them using mutateNumericValue function
    bool is_many_args = !is_one_arg_call(buf_token);
#ifdef TEST_CM
    writeToLogFile("afl_log.log", (is_many_args ? "MANY ARGS" : "ONE ARGE"));
#endif
    if (is_many_args && invalid_tokens) {
        data->input_digit[0] = '\0';
        strcpy(data->input_digit, data->input_args);

	mutateStringValue(data->input_digit, data); // mutate it as a whole

 	// Append the mutated string:
        size_t len = strlen(data->input_digit);
        size_t len_all = strlen(data->out_buff);
        if ((len + len_all) < (MAX_CMDLINE_SIZE - 1))
            strcat(data->out_buff, data->input_digit);

	strcpy((char *)new_buf, data->out_buff);
#ifdef TEST_CM
	writeToLogFile("afl_log.log", ">> After fuzzing bit of args as whole string");
        writeToLogFile("afl_log.log", data->out_buff);
        writeToLogFile("afl_log.log", (char *) new_buf);
#endif
   	return 1;
    }

    // Start parsing the inputs
    char *token = strtok_r(data->input_args, " ", &saveptr1);
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
        if (token != NULL) {
		strncat(data->out_buff, " ", 1); // add back the space
        	if (!invalid_tokens && types_token != NULL)
			types_token = strtok_r(NULL, " ", &saveptr2); // Next type token
	} else {
	   	break; // do not continue if does not have more tokens
	}
   }
   strcpy((char *)new_buf, data->out_buff);
   return 1;
}// End of findAndMutateArgs

// Mutate the binary
bool mutateBinary(uint8_t *new_buf, my_mutator_t *data) {
#ifdef TEST_CM
    writeToLogFile("afl_log.log", "============================================= BIN: try new loop ===>");
    writeToLogFile("afl_log.log", (char *) new_buf);
#endif

    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 0);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { return 0; }              // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { return 0; }                   // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { return 0; }    // t.c.o.types - cannot be smaller

    // Read tokens of data types
    char *buf_token = 0;
    readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
    if (invalid_tokens) return 0; // Cannot mutate

    // Create a new binary to mutate
    char bin_filename[100];
    char type_filename[100];
    generat_new_file_names(data->out_buff, bin_filename, type_filename);
    // Check we have fegit file names:
    if ((strlen(bin_filename) <= 2) ||
        (strlen(type_filename) <= 2)) return 0; // cannot mutate if do not have valid file name

    // Only if okay copy the data
    if (copyFile(data->file_name_types, type_filename)) {
	print_error(">> 14-A Error copying type file", type_filename);
        return 0;
    }
    if (copyFile(data->out_buff, bin_filename)) {
	print_error(">> 14-B Error copying binary file", bin_filename);
	return 0;
    }

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
            print_error(">>-14 Error opening file", bin_filename);
            return 0;
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
            printf(">>-15 Bit at byte %ld, position %d flipped.\n", byte_index, bit_position);
#endif
        }

        fclose(file);
    }

    strcpy((char *)new_buf, data->out_buff);
    return 1;
} // End of mutateBinary


// Mutate the type data
bool mutateTypeData(uint8_t *new_buf, my_mutator_t *data) {
#ifdef TEST_CM
    writeToLogFile("afl_log.log", "============================================= TYPE: try new loop ===>");
    writeToLogFile("afl_log.log", (char *) new_buf);
#endif

    // Init data used for mutating
    initCurrentMutationData(new_buf, data, 0);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { return 0; }		 // All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { return 0; } 		 // t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { return 0; }  // t.c.o.types - cannot be smaller

    // Flag - if any type flipped?
    bool is_type_flipped = false;

    // Remove /n at start
    if (data->input_args[0] != '\0' && data->input_args[0] == '\n') {
        size_t originalLength = strlen(data->input_args);
        // Shift characters to the left
        for (size_t i = 0; data->input_args[i] != '\0'; ++i) {
            data->input_args[i] = data->input_args[i + 1];
        }
        data->input_args[originalLength - 1] = '\0';
    }

#ifdef TEST_CM
    writeToLogFile("afl_log.log", "Types: parsed succesfully data");
    writeToLogFile("afl_log.log", data->file_name_types);
    writeToLogFile("afl_log.log", "====");
    writeToLogFile("afl_log.log", data->out_buff);
    writeToLogFile("afl_log.log", "====");
    writeToLogFile("afl_log.log", data->input_args);
    writeToLogFile("afl_log.log", "====");
#endif

    // Space for temporary manipulations
    char* types_token = 0;
    char *saveptr2=0;
    char type_newbuff[MAX_ARGS_SIZE];
    bool is_many_args = false;
    // Read tokens of data types
    {
        char* buf_token = 0;
        bool rc_types = readTypes(data, &buf_token); bool invalid_tokens = (buf_token == 0);
        if ((!invalid_tokens) && (rc_types)) {
	    types_token = strtok_r(buf_token, " ", &saveptr2);
            if ((types_token != NULL) && (strcmp(types_token,"BINARY") == 0)) {
	        types_token = strtok_r(NULL, " ", &saveptr2); // Next type token, we don't mutate here the binary (different mutation)
                strcpy(type_newbuff, "BINARY");
	    } else {
                // Exit - we don't have enough information to continue this mutation
#ifdef TEST_CM
             	writeToLogFile("afl_log.log", "Invalid tokens - No Binary");
#endif
                return 0;
            }
        } else {
            // Exit - we don't have enough information to continue this mutation
#ifdef TEST_CM
    	    writeToLogFile("afl_log.log", "Invalid tokens");
#endif
            return 0;
        }
        is_many_args = !is_one_arg_call(buf_token);    // Check if a single parameter call
        buf_token = 0;
    }

#ifdef TEST_CM
    writeToLogFile("afl_log.log", "Read tokens");
#endif

    // Try to flip:
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

#ifdef TEST_CM
    writeToLogFile("afl_log.log", "Register new tokens");
#endif

    // If flipped - then copy to a new set of mutated test case
    if (is_type_flipped) {
        // Create a new binary to mutate
        char bin_filename[100];
        char type_filename[100];

        generat_new_file_names(data->out_buff, bin_filename, type_filename);
	// Check we have fegit file names:
	if ((strlen(bin_filename) > 2) &&
            (strlen(type_filename) > 2) &&
	// instead of copying type <copyFile(data->file_name_types, type_filename);>, do this if:
            (writeStringToFile(type_newbuff,type_filename))
           ) {
	    //////// END OF CHECKS ////////////

	    // Create new file after type mutated
	    if (copyFile(data->out_buff, bin_filename)) {
		print_error(">> 17 Failed to copy binary file", bin_filename);
	        return 0;
	    } else {

                // Crete the mutated string to give back to AFL
                strcpy(data->out_buff, bin_filename);
                strcat(data->out_buff, "\n");
                strcat(data->out_buff, data->input_args);
	    }
	} else {
#ifdef TEST_CM
    	    writeToLogFile("afl_log.log", "Failed to copy type file");
#endif
	    // failed to generate a new type file - exit
            print_error(">> 18 Failed to copy type file", type_filename);
	    return 0;
	}
    } else {
#ifdef TEST_CM
    	writeToLogFile("afl_log.log", "No flips");
#endif
        // If no mutation - exit with buffer null.
        return 0;
    }

#ifdef TEST_CM
    writeToLogFile("afl_log.log", "Return mutated types");
#endif

    // Copy the new mutated string to give to AFL
    strcpy((char *)new_buf, data->out_buff);
    return 1;
}
