// You need to use -I/path/to/AFLplusplus/include -I.
#include "afl-fuzz.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

//#define DEBUG_CM 1 // Debug or afl plugin


#ifndef DEBUG_CM
extern AFL_RAND_RETURN rand_next(afl_state_t *afl);
#endif

typedef struct my_mutator {

  afl_state_t *afl;

  char* out_buff; // The whole args in buffers

  char* file_name_types; // The name of the file with types to mutate

  char* input_args; // Keeps the input arguments for mutating

  char* input_digit; // Buffer for register mutations

} my_mutator_t;

#define MAX_CMDLINE_SIZE (250)
#define MAX_FILE_NAME_SIZE (100)
#define MAX_ARGS_SIZE (140)
#define MAX_DATA_SIZE (45)

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

  return data;

}

// Read the types from file
void readTypes(my_mutator_t *data, char* buffer) {
    // Open the file for reading
    FILE *file = fopen(data->file_name_types, "r");
    if (file == NULL) {
        perror("Error opening file");
        buffer = 0;
        return;
    }

    // Allocate space
    if ((buffer = (char *)malloc(MAX_CMDLINE_SIZE)) == NULL) {
        perror("afl buffer malloc failed");
        return;
    }

    // Read the file line by line
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        perror("Error reading file");
        buffer = 0;
        return;
    }

    // Close the file
    fclose(file);
}

// Bit flip integer of 8 bits
void mutateUInt8Value(char *token, my_mutator_t *data, char* format) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    unsigned char num;
    if (sscanf(token, "%hhu", &num) == 1) {
        int bit_pos =
#ifndef DEBUG_CM
                (data->afl) ? rand_below(data->afl, (sizeof(unsigned char) * 8)) :
#endif
                        rand() % (sizeof(unsigned char) * 8); // Random location in the register
        printf("size %d\n",bit_pos);
        num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 16 bits
void mutateUInt16Value(char *token, my_mutator_t *data, char* format) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    unsigned short num;
    if (sscanf(token, "%hu", &num) == 1) {
        int bit_pos =
#ifndef DEBUG_CM
                (data->afl) ? rand_below(data->afl, (sizeof(unsigned short) * 8)) :
#endif
                        rand() % (sizeof(unsigned short) * 8); // Random location in the register

        num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 32 bits
void mutateUInt32Value(char *token, my_mutator_t *data, char* format) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    unsigned int num;
    if (sscanf(token, "%u", &num) == 1) {
        int bit_pos =
#ifndef DEBUG_CM
		(data->afl) ? rand_below(data->afl, (sizeof(unsigned int) * 8)) :
#endif
			rand() % (sizeof(unsigned int) * 8); // Random location in the register

	num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Bit flip integer of 64 bits
void mutateUInt64Value(char *token, my_mutator_t *data, char* format) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    unsigned long num;
    if (sscanf(token, "%lu", &num) == 1) {
        int bit_pos =
#ifndef DEBUG_CM
                (data->afl) ? rand_below(data->afl, (sizeof(unsigned long) * 8)) :
#endif
                        rand() % (sizeof(unsigned long) * 8); // Random location in the register

        num ^= (1ul << bit_pos); // Bit flip it
        sprintf(token, format, num); // Copy it back
    }
}

// Float bit flip
void mutateFloatValue(char *token, my_mutator_t *data) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    float num;
    unsigned int int_repr;
    if (sscanf(token, "%f", &num) == 1) {
        memcpy(&int_repr, &num, sizeof(float)); // dump to uint
        int bit_pos =
#ifndef DEBUG_CM
                (data->afl) ? rand_below(data->afl, (sizeof(unsigned int) * 8)) :
#endif
                        rand() % (sizeof(unsigned int) * 8); // Random location in the register

        int_repr ^= (1u << bit_pos); // Bit flip it
        memcpy(&num, &int_repr, sizeof(float)); // back to float
        sprintf(token, "%f", num); // Copy it back
    }
}

// Double bit flip
void mutateDoubleValue(char *token, my_mutator_t *data) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    double num;
    unsigned long int_repr;
    if (sscanf(token, "%lf", &num) == 1) {
        memcpy(&int_repr, &num, sizeof(double)); // dump to uint
        int bit_pos =
#ifndef DEBUG_CM
                (data->afl) ? rand_below(data->afl, (sizeof(unsigned long) * 8)) :
#endif
                        rand() % (sizeof(unsigned long) * 8); // Random location in the register

        int_repr ^= (1ul << bit_pos); // Bit flip it
        memcpy(&num, &int_repr, sizeof(double)); // back to float
        sprintf(token, "%lf", num); // Copy it back
    }
}


// String bit flip
void mutateStringValue(char *token, my_mutator_t *data) {
#ifdef DEBUG_CM
    static int rand_next = 0;
    srand(time(NULL)+rand_next); // randomize seed
    rand_next++;
#endif

    if (!token) return;

    int pos =
#ifndef DEBUG_CM
    	(data->afl) ? rand_below(data->afl, strlen(token)) :
#endif
        rand() % strlen(token); // Random location in the register

    char* mutate_buf = malloc(MAX_DATA_SIZE);
    sprintf(mutate_buf, "%hhd", (int8_t) token[pos]); // Copy it back
    mutateUInt8Value(mutate_buf,data,"%hhd");

    int integerValue = atoi(mutate_buf); // Convert string to integer
    token[pos] = (char)integerValue; // Convert integer to char

    free(mutate_buf);
}

// Prepare data before mutation
void initCurrentMutationData(uint8_t *new_buf, my_mutator_t *data) {
    // Init buffers
    data->out_buff[0] = '\0';
    data->file_name_types[0] = '\0';
    data->input_args[0] = '\0';

    char *token = strtok((char *)new_buf, "\n");  // Split lines
    strcpy(data->out_buff,token);                 // Keep the name of the binary
    strncat(data->out_buff, "\n", 1);             // Add back the newline
    strcpy(data->file_name_types, token);         // Keep the file name
    strncat(data->file_name_types, ".types", 6);  // Add back the .types ending

    // Add the args lines again
    token = strtok(NULL, "\n");
    if (token != NULL) {
       strcpy(data->input_args, token);
    }
}

// Mutate arguments for the binary in the corpus
void findAndMutateArgs(uint8_t *new_buf, my_mutator_t *data) {
    // Init data used for mutating
    initCurrentMutationData(new_buf, data);
    if ((!data->input_args) || (strlen(data->input_args) == 0)) { new_buf=0; return; }		// All binaries gets at least one char of input
    if ((!data->out_buff) || (strlen(data->out_buff) < 5)) { new_buf=0; return; } 		// t.c.o - cannot be smaller
    if ((!data->file_name_types) || (strlen(data->file_name_types) < 11)) { new_buf=0; return; } // t.c.o.types - cannot be smaller

    // Read tokens of data types
    char* types_token = 0;
    char* buf_token = 0;
    readTypes(data, buf_token); bool invalid_tokens = (!buf_token);
    if (!invalid_tokens) {
	types_token = strtok(buf_token, " ");
        if (types_token != NULL && strcmp(types_token,"BINARY") == 0)
	    types_token = strtok(NULL, " "); // Next type token, we don't mutate here the binary (differnt mutation)
    }

    // Find numeric parts and mutate them using mutateNumericValue function
    char *token = strtok(data->input_args, " ");
    while (token != NULL) {
        // TODO: add a rand to sometimes skip mutation
    	data->input_digit[0] = '\0';
    	strcpy(data->input_digit, token);

        if (invalid_tokens)
    	    mutateUInt32Value(data->input_digit, data, "%u");
	else if (strcmp(types_token,"UINT32") == 0)
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
            mutateDoubleValue(data->input_digit, data);
        else if (strcmp(types_token,"STRING") == 0)
            mutateStringValue(data->input_digit, data);
	else
	    mutateUInt32Value(data->input_digit, data, "%u");

        // Append the mutated string:
        size_t len = strlen(data->input_digit);
        size_t len_all = strlen(data->out_buff);
        if ((len + len_all) < (MAX_CMDLINE_SIZE - 1))
            strncat(data->out_buff, data->input_digit, len);

        // Next iteration:
	token = strtok(NULL, " "); // Next token
        if (token != NULL) strncat(data->out_buff, " ", 1); // add back the space
        if (!invalid_tokens && types_token != NULL) types_token = strtok(NULL, " "); // Next type token
   }
   strcpy((char *)new_buf, data->out_buff);
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

    // bit flip on the arguments
    findAndMutateArgs(new_buf, data);
    if (!new_buf) {
        WARNF("Bad generation for buffer with mutations.");
        return 0;
    }

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

#ifdef DEBUG_CM
int main () {
    my_mutator_t *data = afl_custom_init(0,0); // Create dummy mutator data


    /**************/
    /*   TEST 1   */
    /**************/
    printf(">> TEST 1: mutateUInt32Value with d\n");

    char* input_digit = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit, "-5");
    mutateUInt32Value(input_digit,data,"%d");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit[i] != '\0'; i++) {
        printf("%c", input_digit[i]);
    }
    printf("\n");
    free(input_digit);



    /**************/
    /*   TEST 2   */
    /**************/
    printf("\n>> TEST 2: findAndMutateArgs\n");


    char *input = (char *)malloc(250 * sizeof(char));
    printf("./a.out\n5 5\n");
    strcpy(input, "./a.out\n5 5");
    findAndMutateArgs((unsigned char *)input, data);

    // Print characters until the null-terminator is encountered
    for (int i = 0; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
    free(input);



    /**************/
    /*   TEST 3   */
    /**************/
    printf("\n>> TEST 3: findAndMutateArgs - Real example\n");

    // Test of new ideas:
    char *input2 = (char *)malloc(250 * sizeof(char));
    printf("/home/ubuntu/gem5-ssbse-challenge-2023/afl/input-args/00003.c.o\n0\n");
    strcpy(input2, "/home/ubuntu/gem5-ssbse-challenge-2023/afl/input-args/00003.c.o\n0");
    findAndMutateArgs((unsigned char *)input, data);
    // Print characters until the null-terminator is encountered
    for (int i = 0; input2[i] != '\0'; i++) {
        printf("%c", input2[i]);
    }
    printf("\n");
    free(input2);



    /**************/
    /*   TEST 4   */
    /**************/
    printf("\n>> TEST 4: mutateUInt64Value with ld\n");

    char* input_digit1 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit1, "-5");
    mutateUInt64Value(input_digit1,data,"%ld");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit1[i] != '\0'; i++) {
        printf("%c", input_digit1[i]);
    }
    printf("\n");
    free(input_digit1);



    /**************/
    /*   TEST 5   */
    /**************/
    printf("\n>> TEST 5: mutateUInt64Value with lu\n");

    char* input_digit2 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit2, "-5");
    mutateUInt64Value(input_digit2,data,"%lu");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit2[i] != '\0'; i++) {
        printf("%c", input_digit2[i]);
    }
    printf("\n");
    free(input_digit2);


    /**************/
    /*   TEST 6   */
    /**************/
    printf("\n>> TEST 6: mutateUInt64Value with hd\n");

    input_digit2 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit2, "-5");
    mutateUInt16Value(input_digit2,data,"%hd");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit2[i] != '\0'; i++) {
        printf("%c", input_digit2[i]);
    }
    printf("\n");
    free(input_digit2);



    /**************/
    /*   TEST 7   */
    /**************/
    printf("\n>> TEST 7: mutateUInt64Value with hu\n");

    char* input_digit3 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit3, "-5");
    mutateUInt16Value(input_digit3,data,"%hu");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit3[i] != '\0'; i++) {
        printf("%c", input_digit3[i]);
    }
    printf("\n");
    free(input_digit3);



    /**************/
    /*   TEST 8   */
    /**************/
    printf("\n>> TEST 8: mutateUInt64Value with hhd\n");

    char* input_digit4 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit4, "-5");
    mutateUInt8Value(input_digit4,data,"%hhd");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit4[i] != '\0'; i++) {
        printf("%c", input_digit4[i]);
    }
    printf("\n");
    free(input_digit4);



    /**************/
    /*   TEST 9   */
    /**************/
    printf("\n>> TEST 9: mutateUInt64Value with hhu\n");

    input_digit3 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit3, "-5");
    mutateUInt8Value(input_digit3,data,"%hhu");
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit3[i] != '\0'; i++) {
        printf("%c", input_digit3[i]);
    }
    printf("\n");
    free(input_digit3);



    /**************/
    /*   TEST 10  */
    /**************/
    printf("\n>> TEST 10: mutateUInt64Value with f\n");

    input_digit4 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit4, "-5.0f");
    mutateFloatValue(input_digit4,data);
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit4[i] != '\0'; i++) {
        printf("%c", input_digit4[i]);
    }
    printf("\n");
    free(input_digit4);



    /**************/
    /*   TEST 11  */
    /**************/
    printf("\n>> TEST 11: mutateUInt64Value with lf\n");

    input_digit3 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit3, "5.9");
    mutateDoubleValue(input_digit3,data);
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit3[i] != '\0'; i++) {
        printf("%c", input_digit3[i]);
    }
    printf("\n");
    free(input_digit3);



    /**************/
    /*   TEST 12  */
    /**************/
    printf("\n>> TEST 12: mutateUInt64Value with string\n");

    input_digit3 = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit3, "foo");
    mutateStringValue(input_digit3,data);
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit3[i] != '\0'; i++) {
        printf("%c", input_digit3[i]);
    }
    printf("\n");
    free(input_digit3);


    // Free all
    afl_custom_deinit(data);
}
#endif
