// Modification timestamp: 2023-08-14 15:54:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79450.c
/* PR rtl-optimization/79450 */

unsigned int
foo (unsigned char x, unsigned long long y)
{
  do
    {
      x &= !y;
      x %= 24;
    }
  while (x < y);
  return x + y;
}

int
main (void)
{
  unsigned int x = foo (1, 0);
  if (x != 1)
    __builtin_abort ();
  return 0;
}
