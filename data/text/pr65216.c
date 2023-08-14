// Modification timestamp: 2023-08-14 15:43:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65216.c
/* PR tree-optimization/65216 */

int a, b = 62, e;
volatile int c, d;

int
main ()
{
  int f = 0;
  for (a = 0; a < 2; a++)
    {
      b &= (8 ^ f) & 1;
      for (e = 0; e < 6; e++)
	if (c)
	  f = d;
    }
  if (b != 0)
    __builtin_abort ();
  return 0;
}
