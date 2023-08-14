// Modification timestamp: 2023-08-14 12:36:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021010-1.c
#include <limits.h>

int
sub ()
{
  int dummy = 0, a = 16;

  if (a / INT_MAX / 16 == 0)
    return 0;
  else
    return a / INT_MAX / 16;
}

int
main ()
{
  if (sub () != 0)
    abort ();

  exit (0);
}
