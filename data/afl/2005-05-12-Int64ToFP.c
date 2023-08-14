
// Modification timestamp: 2023-08-10 15:10:14
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long long NX = atoi(argv[1]), X;

  do {
    X = NX;
    printf("%llu = %f  %lld = %f\n", X, (double)X, X, (double)(signed long long)X);
    NX += 1ULL << 60;
  } while (X < NX);

  return 0;
}
