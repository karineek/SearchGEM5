c
// Modification timestamp: 2023-08-10 14:44:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2002-08-02-CastTest2.c

#include <stdio.h>
#include <stdlib.h>

void test(short s1) {
  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */

  printf("s1   = %d\n",   s1);
  printf("us2  = %u\n",   us2);
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
