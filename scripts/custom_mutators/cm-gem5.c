// You need to use -I/path/to/AFLplusplus/include -I.
#include "afl-fuzz.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>

#define DEBUG_CM 1 // Debug or afl plugin


#ifndef DEBUG_CM
extern AFL_RAND_RETURN rand_next(afl_state_t *afl);
#endif

typedef struct my_mutator {

  afl_state_t *afl;

  char* out_buff;

  char* input_digit;

} my_mutator_t;

#define MAX_DATA_SIZE (20)
#define MAX_CMDLINE_SIZE (250)

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

  if ((data->input_digit = (char *)malloc(MAX_DATA_SIZE)) == NULL) {

    perror("afl_custom_init malloc");
    return NULL;

  }

  data->afl = afl;

  return data;

}

void mutateUInt32Value(char *token, my_mutator_t *data) {
    unsigned int num;
    if (sscanf(token, "%u", &num) == 1) {
        int bit_pos =
#ifndef DEBUG_CM
		(data->afl) ? rand_below(data->afl, (sizeof(unsigned int) * 8)) :
#endif
			rand() % (sizeof(unsigned int) * 8); // Random location in the register
        num ^= (1u << bit_pos); // Bit flip it
        sprintf(token, "%d", num); // Copy it back
    }
}

void findAndMutateArgs(uint8_t *new_buf, my_mutator_t *data) {
    data->out_buff[0] = '\0';

    // Find numeric parts and mutate them using mutateNumericValue function
    char *token = strtok((char *)new_buf, " ");
    strcpy(data->out_buff,token);
    token = strtok(NULL, " "); // Next token
    while (token != NULL) {
        strncat(data->out_buff, " ", 1); // add back the space

        // TODO: add a rand to sometimes skip mutation
    	data->input_digit[0] = '\0';
    	strcpy(data->input_digit, token);
    	mutateUInt32Value(data->input_digit, data);
        // TODO: add other data types

        // Append the mutated string
        size_t len = strlen(data->input_digit);
        strncat(data->out_buff, data->input_digit, len);

	token = strtok(NULL, " "); // Next token
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

    size_t new_size = buf_size;
    uint8_t *new_buf = malloc(new_size);
    if (!new_buf)
        return 0;

    // Copy the original input data
    memcpy(new_buf, buf, buf_size);

    // bit flip on the arguments
    findAndMutateArgs(new_buf, data);

    *out_buf = new_buf;
    return new_size;
}

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
void afl_custom_deinit(my_mutator_t *data) {

  free(data->out_buff);
  free(data->input_digit);
  free(data);

}

#ifdef DEBUG_CM
int main () {
    my_mutator_t *data = afl_custom_init(0,0);

    char* input_digit = (char *)malloc(20 * sizeof(char));
    strcpy(input_digit, "5");
    mutateUInt32Value(input_digit,data);
    // Print characters until the null-terminator is encountered
    for (int i = 0; input_digit[i] != '\0'; i++) {
        printf("%c", input_digit[i]);
    }
    printf("\n");
    free(input_digit);


    char *input = (char *)malloc(250 * sizeof(char));
    strcpy(input, "./a.out 5 5");
    findAndMutateArgs((unsigned char *)input, data);

    // Print characters until the null-terminator is encountered
    for (int i = 0; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    // Free all
    afl_custom_deinit(data);
}
#endif
