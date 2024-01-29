// Modification timestamp: 2023-08-14 13:47:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961122-2.c

#include <stdio.h>
#include <stdlib.h>

int f(int a) {
  return ((a >= 0 && a <= 10) && !(a >= 0));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);

  if (f(a)) {
    abort();
  }
  exit(0);
}
