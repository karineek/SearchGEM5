c
// Modification timestamp: 2023-08-04 16:59:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2002-05-02-CastTest.c

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char uint8;
typedef signed char int8;

int main(int argc, char** argv) {
    char c1 = (argc >= 2) ? atoi(argv[1]) : 100;
    short s1 = (argc >= 3) ? atoi(argv[2