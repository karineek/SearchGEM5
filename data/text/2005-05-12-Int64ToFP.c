
// Modification timestamp: 2023-08-10 15:10:14
// Original Source: https://github.com/llvm/llvm-test-suite

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
