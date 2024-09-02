// Modification timestamp: 2023-08-14 15:47:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68648.c

#include <stdio.h>
#include <stdlib.h>

int foo() {
  return 123;
}

int bar() {
  int c = 1;
  c |= 4294967295 ^ (foo() | 4073709551608);
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (bar() != atoi(argv[1])) {
    abort();
  }
  
  return 0;
}
