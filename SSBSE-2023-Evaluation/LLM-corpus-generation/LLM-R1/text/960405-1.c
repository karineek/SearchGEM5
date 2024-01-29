// Modification timestamp: 2023-08-14 13:45:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960405-1.c
#define X  5.9486574767861588254287966331400356538172e4931L

long double x = X + X;
long double y = 2.0L * X;

main ()
{
#if ! defined (__vax__) && ! defined (_CRAY)
  if (x != y)
    abort ();
#endif
  exit (0);
}
