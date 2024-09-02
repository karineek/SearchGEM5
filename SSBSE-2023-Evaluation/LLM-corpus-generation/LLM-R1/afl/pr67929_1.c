// Modification timestamp: 2023-08-14 15:45:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67929_1.c

#include <stdio.h>
#include <stdlib.h>

int foo(float a) {
  return a * 4.9f;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo(atof(argv[1])) != 49) {
    abort();
  }

  return 0;
}
