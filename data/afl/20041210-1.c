// Modification timestamp: 2023-08-14 13:00:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041210-1.c

#include <limits.h>
#include <stdlib.h>

int x[4] = { INT_MIN / 2, INT_MAX, 2, 4 };

int
main (int argc, char *argv[])
{
  if (x[0] < x[1])
    if ((x[2] & x[3]) < atoi(argv[1]))
      abort ();
  exit (0);
}
