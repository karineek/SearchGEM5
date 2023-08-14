
// Modification timestamp: 2023-08-10 15:52:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/Generic/2003-05-21-UnionBitfields.c

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
  printf("%d %d\n", target_isinf(1234.42), target_isinf(x));
  return 0;
}
