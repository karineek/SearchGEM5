// Modification timestamp: 2023-08-14 15:48:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68841.c

#include <stdio.h>
#include <stdlib.h>

static inline int foo(int *x, int y) {
  int z = *x;
  while (y > z)
    z *= 2;
  return z;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 1; i < 17; i++) {
    int j;
    int k;
    j = foo(&i, 7);
    if (i >= 7)
      k = i;
    else if (i >= 4)
      k = 8 + (i - 4) * 2;
    else if (i == 3)
      k = 12;
    else
      k = 8;
    if (j != k)
      __builtin_abort();
  }
  return 0;
}

