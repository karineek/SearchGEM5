// Modification timestamp: 2023-08-14 15:30:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58364.c
/* PR tree-optimization/58364 */

int a = 1, b, c;

int
foo (int x)
{
  return x < 0 ? 1 : x;
}

int
main ()
{
  if (foo (a > c == (b = 0)))
    __builtin_abort ();
  return 0;
}
