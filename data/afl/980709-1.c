// Modification timestamp: 2023-08-14 13:51:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980709-1.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile double a = atof(argv[1]);
  double c = pow(a, 1.0/3.0);
  if (c + 0.1 > 3.174802 && c - 0.1 < 3.174802)
    exit(0);
  else
    abort();
}
