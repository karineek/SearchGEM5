// Modification timestamp: 2023-08-14 15:52:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr77767.c
/* PR c/77767 */

void
foo (int a, int b[a++], int c, int d[c++])
{
  if (a != 2 || c != 2)
    __builtin_abort ();
}

int
main ()
{
  int e[10];
  foo (1, e, 1, e);
  return 0;
}
