// Modification timestamp: 2023-08-14 17:11:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-08-02-CastTest.c
#include <stdlib.h>

#include <stdio.h>

unsigned test(unsigned X) {
  return (unsigned char)X;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned X = atoi(argv[1]);
  printf("%d\n", test(X));
  return 0;
}
