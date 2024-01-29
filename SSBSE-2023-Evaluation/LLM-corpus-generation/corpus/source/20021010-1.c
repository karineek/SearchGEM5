// Modification timestamp: 2023-08-14 12:36:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021010-1.c
#include <stdio.h>

#include <limits.h>
#include <stdlib.h>

int sub(int dummy, int a) {
  if (a / INT_MAX / 16 == 0)
    return 0;
  else
    return a / INT_MAX / 16;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <dummy> <a>\n", argv[0]);
    return 1;
  }

  int dummy = atoi(argv[1]);
  int a = atoi(argv[2]);

  if (sub(dummy, a) != 0)
    abort();

  exit(0);
}
