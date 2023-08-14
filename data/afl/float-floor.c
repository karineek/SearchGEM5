// Modification timestamp: 2023-08-14 14:26:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/float-floor.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if(__SIZEOF_DOUBLE__==8)
double d = 1024.0 - 1.0 / 32768.0;
#else
double d = 1024.0 - 1.0 / 16384.0;
#endif

extern double floor(double);
extern float floorf(float);
extern void abort();

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double df = floor(atof(argv[1]));
  float f1 = (float)floor(atof(argv[1]));

  if ((int)df != 1023 || (int)f1 != 1023)
    abort();

  return 0;
}
