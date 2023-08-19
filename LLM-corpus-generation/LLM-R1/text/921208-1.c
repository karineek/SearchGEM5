// Modification timestamp: 2023-08-14 13:32:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921208-1.c
double
f(double x)
{
  return x*x;
}

double
Int(double (*f)(double), double a)
{
  return (*f)(a);
}

main()
{
  if (Int(&f,2.0) != 4.0)
    abort();
  exit (0);
}
