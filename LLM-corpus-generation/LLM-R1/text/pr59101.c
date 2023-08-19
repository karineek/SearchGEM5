// Modification timestamp: 2023-08-14 15:36:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59101.c
/* PR target/59101 */

__attribute__((noinline, noclone)) int
foo (int a)
{
  return (~a & 4102790424LL) > 0 | 6;
}

int
main ()
{
  if (foo (0) != 7)
    __builtin_abort ();
  return 0;
}
