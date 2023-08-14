// Modification timestamp: 2023-08-14 15:50:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70586.c
/* PR tree-optimization/70586 */

int a, e, f;
short b, c, d;

int
foo (int x, int y)
{
  return (y == 0 || (x && y == 1)) ? x : x % y;
}

static short
bar (void)
{
  int i = foo (c, f);
  f = foo (d, 2);
  int g = foo (b, c);
  int h = foo (g > 0, c);
  c = (3 >= h ^ 7) <= foo (i, c);
  if (foo (e, 1))
    return a;
  return 0;
}

int
main ()
{
  bar ();
  return 0;
}
