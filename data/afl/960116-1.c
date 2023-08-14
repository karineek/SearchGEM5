// Modification timestamp: 2023-08-14 13:43:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960116-1.c

#include <stdio.h>
#include <stdlib.h>

static inline int p(int *p) {
  return !((long)p & 1);
}

int f(int *q) {
  if (p(q) && *q)
    return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  if (f((int *)atoi(argv[1])) != 0)
    abort();
  exit(0);
}
