// Modification timestamp: 2023-08-14 17:10:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-02-CastTest1.c
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char c0 = atoi(argv[1]);
  unsigned char c1 = atoi(argv[2]);
  printf("bs0  = %d %d\n", c0, c1);
  return 0;
}
