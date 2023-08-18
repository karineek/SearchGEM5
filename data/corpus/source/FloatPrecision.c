// Modification timestamp: 2023-08-14 17:27:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/FloatPrecision.c

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
