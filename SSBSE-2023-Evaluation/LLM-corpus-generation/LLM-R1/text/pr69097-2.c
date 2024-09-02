// Modification timestamp: 2023-08-14 15:48:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69097-2.c
/* PR tree-optimization/69097 */

__attribute__((noinline, noclone)) int
f1 (int x, int y)
{
  return x % y;
}

__attribute__((noinline, noclone)) int
f2 (int x, int y)
{
  return x % -y;
}

__attribute__((noinline, noclone)) int
f3 (int x, int y)
{
  int z = -y;
  return x % z;
}

int
main ()
{
  if (f1 (-__INT_MAX__ - 1, 1) != 0
      || f2 (-__INT_MAX__ - 1, -1) != 0
      || f3 (-__INT_MAX__ - 1, -1) != 0)
    __builtin_abort ();
  return 0;
}
