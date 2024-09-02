// Modification timestamp: 2023-08-14 17:11:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-08-02-CastTest2.c
#include <stdlib.h>

#include <stdio.h>

void test(short s1) {
  unsigned short us2 = (unsigned short) s1;

  printf("s1   = %hd\n",   s1);
  printf("us2  = %hu\n",   us2);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  short s1 = atoi(argv[1]);
  test(s1);
  return 0;
}
