// Modification timestamp: 2023-08-14 14:12:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/cbrt.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double cbrtl(double x) {
  return cbrt(x);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double x = atof(argv[1]);
  if ((int) (cbrtl(x) + 0.5) != 3)
    abort();

  exit(0);
}
