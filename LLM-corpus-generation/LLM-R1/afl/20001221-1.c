// Modification timestamp: 2023-08-14 11:55:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001221-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned long long a;
  if (!(a = strtoull(argv[1], NULL, 0)))
    abort();
  exit(0);
}

Note: The converted code assumes that the hexadecimal value is input as a command line argument.