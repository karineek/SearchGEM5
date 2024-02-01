/**
 * @file test-main.c
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

// Compilation flags. Read the project README.md to understand how to use thses.
//#define DEBUG_CM 1 // Debug or afl plugin

#include "cm-gem5.h"
#include "utils.h"

// Main for tesing the cm-gem5 mutator basic functionality
#ifdef DEBUG_CM
int main (int argc, char *argv[]) {
    my_mutator_t *data = afl_custom_init(0,0); // Create dummy mutator data

#ifndef TEST_CM
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
    strcpy(input_digit3, "5.967867868");
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
#else

    printf("Start the test!\n");
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *input_string = argv[1];
    printf(">>>> Input String: %s\n", input_string);
    printf(">>>> TEST: mutateBinary or findAndMutateArgs\n");
    if (!data) printf(">> ERROR AFL OBJECT WAS NOT ALLOCATED\n");
    char *input = (char *)malloc(250 * sizeof(char));
    strcpy(input, input_string);
    /*findAndMutateArgs*/mutateBinary((unsigned char *)input, data);

    // Print characters until the null-terminator is encountered
    printf(">>>> End of test\n>>>>>> ");
    for (int i = 0; input[i] != '\0'; i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    printf("Result of test:\n");
    printf(">>>> Output Buffer String: %s\n", data->out_buff);
    printf(">>>> Output Buffer String: %s\n", data->file_name_types);
    printf(">>>> Output Buffer String: %s\n", data->input_args);
    if (strlen(data->input_args) < 1)
        printf(">>>> DIAGNOSIS: Input file is invalid. Do you have two lines in .txt file?\n");

#endif


    // Free all
    afl_custom_deinit(data);
}
#endif
