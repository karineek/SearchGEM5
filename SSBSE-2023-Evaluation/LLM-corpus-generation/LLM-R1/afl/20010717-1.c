// Modification timestamp: 2023-08-14 11:59:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010717-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int j = atoi(argv[2]);
  unsigned long u = i + j;

  unsigned long r1 = u >> 1;
  unsigned long r2 = ((unsigned long)(i + j)) >> 1;

  if (r1 != r2)
    abort();

  return 0;
}
