// Modification timestamp: 2023-08-14 17:11:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-09-ArrayResolution.c
#include <stdio.h>
#define NUM 32

int Array[];
int Array[NUM];
int Foo;            /* If writing to the wrong "Array", this will get clobbered */

int main() {
  unsigned i;
  for (i = 0; i != NUM; ++i)
    Array[i] = 5;

  printf("%d\n", Foo);
  return 0;
}

