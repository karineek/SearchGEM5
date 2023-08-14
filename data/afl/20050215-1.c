// Modification timestamp: 2023-08-14 13:02:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050215-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct { char c[8]; } V;
typedef __SIZE_TYPE__ size_t;
V v;
void abort (void);

int main(int argc, char *argv[]) {
  V *w = &v;
  if (((size_t) ((float *) ((size_t) w & ~(size_t) 3)) % 8) != 0 || ((size_t) w & 1))
  {
#ifndef __ELF__
    if (((size_t) &v & 7) == 0)
#endif
      abort();
  }

  return 0;
}
