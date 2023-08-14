// Modification timestamp: 2023-08-14 16:01:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85529-1.c
/* PR tree-optimization/85529 */

struct S { int a; };

int b, c = 1, d, e, f;
static int g;
volatile struct S s;

signed char
foo (signed char i, int j)
{
  return i < 0 ? i : i << j;
}

int
main ()
{
  signed char k = -83;
  if (!d)
    goto L;
  k = e || f;
L:
  for (; b < 1; b++)
    s.a != (k < foo (k, 2) && (c = k = g));
  if (c != 1)
    __builtin_abort ();
  return 0;
}
