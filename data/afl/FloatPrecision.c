
// Modification timestamp: 2023-08-10 15:38:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Benchmarks/Misc/FloatPrecision.c

#include <stdio.h>
#include <stdlib.h>

void print(float X) {
  printf("%f\n", X*2147483647);
  printf("%x\n", (int)(unsigned long long)(X*2147483647));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  float X = atof(argv[1]);
  print(X);

  return 0;
}
