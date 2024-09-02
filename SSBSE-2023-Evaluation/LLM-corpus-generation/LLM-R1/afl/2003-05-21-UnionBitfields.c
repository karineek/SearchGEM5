// Modification timestamp: 2023-08-14 17:32:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-21-UnionBitfields.c

#include <stdio.h>
#include <math.h>

int target_isinf(double x) {
  union {
    double d;
    struct {
      unsigned mantissa2;
      unsigned mantissa1 : 20;
      unsigned exponent  : 11;
      unsigned sign      :  1;
    } big_endian;
  } u;

  u.d = x;
  return (u.big_endian.exponent == 2047 && u.big_endian.mantissa1 == 0 && u.big_endian.mantissa2 == 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double x = atof(argv[1]);
  printf("%d\n", target_isinf(x));
  return 0;
}

