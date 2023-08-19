// Modification timestamp: 2023-08-14 13:41:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950511-1.c
main ()
{
  unsigned long long xx;
  unsigned long long *x = (unsigned long long *) &xx;

  *x = -3;
  *x = *x * *x;
  if (*x != 9)
    abort ();
  exit (0);
}
