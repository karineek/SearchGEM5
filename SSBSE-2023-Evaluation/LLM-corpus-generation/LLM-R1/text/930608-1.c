// Modification timestamp: 2023-08-14 13:34:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930608-1.c
double f (double a) {}
double (* const a[]) (double) = {&f};

main ()
{
  double (*p) ();
  p = &f;
  if (p != a[0])
    abort ();
  exit (0);
}
