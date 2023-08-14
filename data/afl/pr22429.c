// Modification timestamp: 2023-08-14 14:47:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22429.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

#define N (1 << (sizeof(int) * __CHAR_BIT__ - 2))

int f(int n) {
  if (-N <= n && n <= N - 1)
    return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (f(n))
    abort();
  return 0;
}
