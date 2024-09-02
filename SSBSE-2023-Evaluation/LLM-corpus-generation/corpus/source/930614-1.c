// Modification timestamp: 2023-08-14 13:34:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930614-1.c

#include <stdio.h>
#include <stdlib.h>

void f(double *ty) {
  *ty = -1.0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double foo[6];
  double tx = atof(argv[1]);
  double ty, d;

  f(&ty);

  if (ty < 0)
    ty = -ty;
  d = (tx > ty) ? tx : ty;
  if (ty != d)
    abort();
  exit(0);
}
