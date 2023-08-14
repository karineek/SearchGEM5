// Modification timestamp: 2023-08-14 13:35:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930702-1.c
fp (double a, int b)
{
  if (a != 33 || b != 11)
    abort ();
}

main ()
{
  int (*f) (double, int) = fp;

  fp (33, 11);
  f (33, 11);
  exit (0);
}
