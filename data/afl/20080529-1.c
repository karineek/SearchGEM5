// Modification timestamp: 2023-08-14 13:14:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080529-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int test(float c) {
  return !!c * 7LL == 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  float c = atof(argv[1]);
  if (test(c) != 0)
    abort();
  return 0;
}
