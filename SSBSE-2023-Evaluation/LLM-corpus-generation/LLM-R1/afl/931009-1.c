// Modification timestamp: 2023-08-14 13:39:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931009-1.c

#include <stdio.h>
#include <stdlib.h>

static void g(int *out, int size, int lo, int hi) {
  int j;

  for (j = 0; j < size; j++)
    out[j] = j * (hi - lo);
}

void f() {
  int a[2];

  g(a, 2, 0, 1);

  if (a[0] != 0 || a[1] != 1)
    abort();
}

int main(int argc, char *argv[]) {
  f();
  exit(0);
}
