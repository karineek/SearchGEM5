// Modification timestamp: 2023-08-14 13:32:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921207-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned int f(unsigned int b) {
  if (b > ~0U)
    b = ~0U;

  return b;
}

int main(int argc, char *argv[]) {
  if (f(0) != 0)
    abort();

  exit(0);
}
