// Modification timestamp: 2023-08-14 14:31:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-3.c
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
      g (i * INT_MAX / 2);
    }
  while (--i > 0);
}

main ()
{
  f (4);
  if (n != 4)
    abort ();
  exit (0);
}
