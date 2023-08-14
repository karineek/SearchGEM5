
// Modification timestamp: 2023-08-04 16:59:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/simple/CastTest2.c

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int
main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short s1 = atoi(argv[1]);

  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */
  printf("us2  = %u\n",   us2);
  return 0;
}
