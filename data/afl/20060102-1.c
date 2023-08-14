// Modification timestamp: 2023-08-14 13:05:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060102-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

int f(int x)
{
  return (x >> (sizeof (x) * __CHAR_BIT__ - 1)) ? -1 : 1;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile int one = atoi(argv[1]);

  /* Test that the function above returns different values for
     different signs. */
  if (f(one) == f(-one))
    abort ();
  return 0;
}

