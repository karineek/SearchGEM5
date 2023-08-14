// Modification timestamp: 2023-08-14 13:47:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961122-2.c
int
f (int a)
{
  return ((a >= 0 && a <= 10) && ! (a >= 0));
}

main ()
{
  if (f (0))
    abort ();
  exit (0);
}
