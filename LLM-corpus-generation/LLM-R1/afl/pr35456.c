// Modification timestamp: 2023-08-14 14:57:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35456.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double not_fabs(double x) {
  return x >= 0.0 ? x : -x;
}

int main(int argc, char *argv[]) {
  double x = atof(argv[1]);
  double y;

  y = not_fabs(x);

  if (!__builtin_signbit(y))
    abort();

  return 0;
}
