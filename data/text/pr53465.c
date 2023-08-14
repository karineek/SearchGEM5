// Modification timestamp: 2023-08-14 15:23:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53465.c
/* PR tree-optimization/53465 */

extern void abort ();

static const int a[] = { 1, 2 };

void
foo (const int *x, int y)
{
  int i;
  int b = 0;
  int c;
  for (i = 0; i < y; i++)
    {
      int d = x[i];
      if (d == 0)
	break;
      if (b && d <= c)
	abort ();
      c = d;
      b = 1;
    }
}

int
main ()
{
  foo (a, 2);
  return 0;
}
