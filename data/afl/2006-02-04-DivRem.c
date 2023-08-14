// Modification timestamp: 2023-08-14 17:18:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2006-02-04-DivRem.c

#include <stdio.h>
#include <stdlib.h>

void test(unsigned X, unsigned Y) {
  printf("%u %u %u %u\n", X, Y, X / (8 << (Y&15)), X % (8 << (Y&15)));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  long long l;

  for(i=10; i<139045193; i*=-3) {
    test(i, i^12345);
    i++;
  }

  return(0);
}
