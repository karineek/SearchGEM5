// Modification timestamp: 2023-08-14 17:17:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-05-12-Int64ToFP.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long long NX = atoi(argv[1]);
  unsigned long long X;

  do {
    X = NX;
    printf("%llu = %f  %lld = %f\n", X, (double)X, X, (double)(signed long long)X);
    NX += 1ULL << 60;
  } while (X < NX);

  return 0;
}
