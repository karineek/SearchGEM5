// Modification timestamp: 2023-08-14 13:35:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930818-1.c

#include <stdio.h>
#include <stdlib.h>

static double one = 1.0;

int f(double one) {
  int colinear;
  colinear = (one == 0.0);
  if (colinear)
    abort ();
  return colinear;
}

int main(int argc, char *argv[]) {
  if (f(one)) abort();
  exit(0);
}
