// Modification timestamp: 2023-08-14 14:18:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-5.c

#include <stdio.h>
#include <stdlib.h>

float __complex__ p(float __complex__ a, float __complex__ b) {
  return a + b;
}

int main(int argc, char *argv[]) {
  float __complex__ x = atof(argv[1]) + atof(argv[2]) * (1.0fi);
  float __complex__ y = atof(argv[3]) + atof(argv[4]) * (1.0fi);
  float __complex__ w = atof(argv[5]) + atof(argv[6]) * (1.0fi);
  float __complex__ z;

  z = p(x, y);
  y = p(x, 1.0f / z);
  if (z != w)
    abort();
  exit(0);
}

Note: You need to provide the necessary arguments for `atof()` function calls when executing the program.