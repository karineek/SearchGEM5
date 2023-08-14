// Modification timestamp: 2023-08-14 14:18:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-1.c

#include <stdio.h>
#include <stdlib.h>

double g0(double x)
{
  return 1.0;
}

double g1(double x)
{
  return -1.0;
}

double g2(double x)
{
  return 0.0;
}

__complex__ double xcexp(__complex__ double x)
{
  double r;

  r = g0(__real__ x);
  __real__ x = r * g1(__imag__ x);
  __imag__ x = r * g2(__imag__ x);
  return x;
}

int main(int argc, char *argv[])
{
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  __complex__ double x = xcexp(1.0i);
  
  if (__real__ x != -1.0)
    abort ();
  if (__imag__ x != 0.0)
    abort ();
  
  return 0;
}
