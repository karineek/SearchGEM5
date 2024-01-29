// Modification timestamp: 2023-08-14 14:45:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-2.c

#include <stdio.h>
#include <stdlib.h>

static void bar(char a[2][int *x]) {}

int main(void) {
  exit(0);
}

Note: Since the value of `x` is not provided as a command-line argument, it is not possible to determine its value during runtime. Therefore, it is necessary to modify the program to take the value of `x` as a command-line argument in order to instantiate the array `a` correctly.