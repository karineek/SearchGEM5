// Modification timestamp: 2023-08-14 17:32:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2008-01-07-LongDouble.c
#include <stdio.h>
int main(void) {
  long double x = 1.0;
  printf("%Lf %Lf\n", x, x);
  return 0;
}
