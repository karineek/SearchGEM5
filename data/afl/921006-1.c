// Modification timestamp: 2023-08-14 13:30:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921006-1.c
The program you provided seems to be missing some includes and has a few syntax errors. Here's a corrected version:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (strcmp("X", "") < 0)
    abort();
  
  exit(0);
}


Please note that the `main()` function should have a return type of `int`.