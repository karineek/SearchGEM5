// Modification timestamp: 2023-08-14 15:45:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67929_1.c
int __attribute__ ((noinline, noclone))
foo (float a)
{
  return a * 4.9f;
}


int
main (void)
{
  if (foo (10.0f) != 49)
    __builtin_abort ();

  return 0;
}
