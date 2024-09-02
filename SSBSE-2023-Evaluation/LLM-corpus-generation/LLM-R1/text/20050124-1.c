// Modification timestamp: 2023-08-14 13:01:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050124-1.c
/* PR rtl-optimization/19579 */

extern void abort (void);

int
foo (int i, int j)
{
  int k = i + 1;

  if (j)
    {
      if (k > 0)
	k++;
      else if (k < 0)
	k--;
    }

  return k;
}

int
main (void)
{
  if (foo (-2, 0) != -1)
    abort ();
  if (foo (-1, 0) != 0)
    abort ();
  if (foo (0, 0) != 1)
    abort ();
  if (foo (1, 0) != 2)
    abort ();
  if (foo (-2, 1) != -2)
    abort ();
  if (foo (-1, 1) != 0)
    abort ();
  if (foo (0, 1) != 2)
    abort ();
  if (foo (1, 1) != 3)
    abort ();
  return 0;
}
