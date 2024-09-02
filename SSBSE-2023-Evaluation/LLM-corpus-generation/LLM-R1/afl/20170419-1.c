// Modification timestamp: 2023-08-14 13:23:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20170419-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int x;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile int a = atoi(argv[1]);
  volatile int b = -INT_MAX;
  int j;

  for(j = 0; j < 18; j += 1) {
    x = ((a == 0) != (b - (int)(INT_MIN)));
  }

  if (x != 0)
    __builtin_abort();

  return 0;
}
