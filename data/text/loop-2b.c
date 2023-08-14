// Modification timestamp: 2023-08-14 14:30:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-2b.c
#include <limits.h>

int a[2];

f (int i)
{
  for (; i < INT_MAX; i++)
    {
      a[i] = -2;
      if (&a[i] == &a[1])
	break;
    }
}

main ()
{
  a[0] = a[1] = 0;
  f (0);
  if (a[0] != -2 || a[1] != -2)
    abort ();
  exit (0);
}
