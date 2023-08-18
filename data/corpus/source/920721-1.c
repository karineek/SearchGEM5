// Modification timestamp: 2023-08-14 13:28:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-1.c

#include <stdio.h>
#include <stdlib.h>

long f(short a, short b) {
  return (long)a / b;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  short a = atoi(argv[1]);
  short b = atoi(argv[2]);

  if (f(a, b) != 32768L) {
    abort();
  } else {
    exit(0);
  }
}
