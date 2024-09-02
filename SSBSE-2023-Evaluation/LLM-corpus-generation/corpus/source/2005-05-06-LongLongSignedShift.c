// Modification timestamp: 2023-08-14 17:32:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2005-05-06-LongLongSignedShift.c
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  printf("%lld\n", (atoi(argv[1])-100LL) >> 38);

  return 0;
}
