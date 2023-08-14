c
// Modification timestamp: 2023-08-04 16:59:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/CastTest3.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short s1 = atoi(argv[1]);
  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */

  printf("s1   = %d\n",   s1);
  printf("us2  = %u\n",   us2);
  return 0;
}
