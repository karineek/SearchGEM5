// Modification timestamp: 2023-08-14 15:28:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57875.c
/* PR rtl-optimization/57875 */

extern void abort (void);
int a[1], b, c, d, f, i;
char e[1];

int
main ()
{
  for (; i < 1; i++)
    if (!d)
      {
	if (!c)
	  f = 2;
	e[0] &= f ^= 0;
      }
  b = a[e[0] >> 1 & 1];
  if (b != 0)
    abort ();
  return 0;
}
