// Modification timestamp: 2023-08-14 17:18:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2006-12-01-float_varg.c

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  float f1 = atof(argv[1]);
  float f2 = atof(argv[2]);
  float f3 = atof(argv[3]);
  float f4 = atof(argv[4]);

  printf("foo %f %f %f %f\n", f1, f2, f3, f4);
  return 0;
}
