// Modification timestamp: 2023-08-14 15:36:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59387.c
/* PR tree-optimization/59387 */

int a, *d, **e = &d, f;
char c;
struct S { int f1; } b;

int
main ()
{
  for (a = -19; a; a++)
    {
      for (b.f1 = 0; b.f1 < 24; b.f1++)
	c--;
      *e = &f;
      if (!d)
	return 0;
    }
  return 0;
}
