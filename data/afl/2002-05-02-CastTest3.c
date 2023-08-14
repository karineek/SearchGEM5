// Modification timestamp: 2023-08-14 17:11:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-02-CastTest3.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  short s1 = atoi(argv[1]);
  unsigned short us2 = (unsigned short)s1;

  printf("s1   = %d\n", s1);
  printf("us2  = %u\n", us2);
  return 0;
}
