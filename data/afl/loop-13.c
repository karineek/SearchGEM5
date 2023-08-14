// Modification timestamp: 2023-08-14 14:30:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-13.c

#include <stdio.h>
#include <stdlib.h>

#define TYPE long

void scale(TYPE *alpha, TYPE *x, int n) {
  int i, ix;

  if (*alpha != 1) {
    for (i = 0, ix = 0; i < n; i++, ix += 2) {
      TYPE tmpr, tmpi;
      tmpr = *alpha * x[ix];
      tmpi = *alpha * x[ix + 1];
      x[ix] = tmpr;
      x[ix + 1] = tmpi;
    }
  }
}

int main(int argc, char *argv[]) {
  int i;
  TYPE x[10];
  TYPE alpha;

  if (argc != 12) {
    printf("Usage: %s <alpha> <x0> <x1> <x2> <x3> <x4> <x5> <x6> <x7> <x8> <x9>\n", argv[0]);
    return 1;
  }

  alpha = atol(argv[1]);
  for (i = 0; i < 10; i++) {
    x[i] = atol(argv[i + 2]);
  }

  scale(&alpha, x, 5);

  if (x[9] != 18) {
    abort();
  }

  return 0;
}
