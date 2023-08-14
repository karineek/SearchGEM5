// Modification timestamp: 2023-08-14 17:17:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-05-12-Int64ToFP.c

#include <stdio.h>


int main() {
  unsigned long long NX = 124, X;

  do {
    X = NX;
    printf("%llu = %f  %lld = %f\n", X, (double)X, X, (double)(signed long long)X);
    NX += 1ULL << 60;
  } while (X < NX);

  return 0;
}
