// Modification timestamp: 2023-08-14 13:21:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140212-1.c
/* PR rtl-optimization/60116 */
/* Reported by Zhendong Su <su@cs.ucdavis.edu> */

extern void abort (void);

int a, b, c, d = 1, e, f = 1, h, i, k;
char g, j;

void
fn1 (void)
{
  int l;
  e = 0;
  c = 0;
  for (;;)
    {
      k = a && b;
      j = k * 54;
      g = j * 147;
      l = ~g + (long long) e && 1;
      if (d)
	c = l;
      else
	h = i = l * 9UL;
      if (f)
	return;
    }
}

int
main (void)
{
  fn1 ();
  if (c != 1)
    abort ();
  return 0;
}
