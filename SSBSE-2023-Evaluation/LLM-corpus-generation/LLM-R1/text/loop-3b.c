// Modification timestamp: 2023-08-14 14:31:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-3b.c
#include <limits.h>

int n = 0;

g (i)
{
  n++;
}

f (m)
{
  int i;
  i = m;
  do
    {
      g (i * 4);
      i -= INT_MAX / 8;
    }
  while (i > 0);
}

main ()
{
  f (INT_MAX/8*4);
  if (n != 4)
    abort ();
  exit (0);
}
