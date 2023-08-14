// Modification timestamp: 2023-08-14 15:53:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78791.c
/* PR target/78791 */

__attribute__((used, noinline, noclone)) unsigned long long
foo (unsigned long long x, unsigned long long y, unsigned long long z)
{
  unsigned long long a = x / y;
  unsigned long long b = x % y;
  a |= z;
  b ^= z;
  return a + b;
}

int
main ()
{
  if (foo (64, 7, 0) != 10 || foo (28, 3, 2) != 14)
    __builtin_abort ();
  return 0;
}
