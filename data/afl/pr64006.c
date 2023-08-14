// Modification timestamp: 2023-08-14 15:41:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64006.c

#include <stdio.h>
#include <stdlib.h>
#define __CHAR_BIT__ 8

int v;

long __attribute__ ((noinline, noclone))
test (long *x, int y)
{
  int i;
  long s = 1;
  for (i = 0; i < y; i++)
    if (__builtin_mul_overflow (s, x[i], &s))
      v++;
  return s;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  long d[7] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]) };
  long r = test (d, 7);

  if (sizeof (long) * __CHAR_BIT__ == 64 && v != 1)
    __builtin_abort ();
  else if (sizeof (long) * __CHAR_BIT__ == 32 && v != 4)
    __builtin_abort ();
  return 0;
}


Note that since `d` is an array of `long`, the command-line arguments are assumed to be integers and are converted using `atoi()`. Make sure to provide 7 command-line arguments when executing the program.