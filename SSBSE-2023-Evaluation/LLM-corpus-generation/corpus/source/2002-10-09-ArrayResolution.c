// Modification timestamp: 2023-08-14 17:11:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-09-ArrayResolution.c

#include <stdio.h>
#include <stdlib.h>

#define NUM 32

int Array[];
int Array[NUM];
int Foo;            /* If writing to the wrong "Array", this will get clobbered */

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  unsigned i;
  for (i = 0; i != x; ++i)
    Array[i] = 5;

  printf("%d\n", Foo);
  return 0;
}
