// Modification timestamp: 2023-08-14 17:02:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vla-dealloc-1.c

/* VLAs should be deallocated on a jump to before their definition,
   including a jump to a label in an inner scope.  PR 19771.  */
/* { dg-require-effective-target alloca } */

#include <stdio.h>
#include <stdlib.h>

#if (__SIZEOF_INT__ <= 2)
#define LIMIT 10000
#else
#define LIMIT 1000000
#endif

void *volatile p;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (0) {
    lab:;
  }
  int x[n % 1000 + 1];
  x[0] = 1;
  x[n % 1000] = 2;
  p = x;
  n++;
  if (n < LIMIT)
    goto lab;
  return 0;
}

