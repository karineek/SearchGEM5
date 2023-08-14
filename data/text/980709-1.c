// Modification timestamp: 2023-08-14 13:51:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980709-1.c
/* { dg-xfail-if "Can not call system libm.a with -msoft-float" { powerpc-*-aix* rs6000-*-aix* } { "-msoft-float" } { "" } } */
#include <math.h>

main()
{
  volatile double a;
  double c;
  a = 32.0;
  c = pow(a, 1.0/3.0);
  if (c + 0.1 > 3.174802
      && c - 0.1 < 3.174802)
    exit (0);
  else
    abort ();
}
