// Modification timestamp: 2023-08-14 14:18:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-2.c

#include <stdio.h>
#include <stdlib.h>

__complex__ double f (__complex__ double x, __complex__ double y)
{
  x += y;
  return x;
}

int main(int argc, char *argv[]) {
  __complex__ double ag = atof(argv[1]) + atof(argv[2])*I;
  __complex__ double bg = atof(argv[3]) + atof(argv[4])*I;
  __complex__ double a, b, c;

  a = ag;
  b = atof(argv[5]) + atof(argv[6])*I;
  c = f (a, b);

  if (a != atof(argv[7]) + atof(argv[8])*I)
    abort ();
  if (b != atof(argv[9]) + atof(argv[10])*I)
    abort ();
  if (c != atof(argv[11]) + atof(argv[12])*I)
    abort ();

  exit (0);
}
