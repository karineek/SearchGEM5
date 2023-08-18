// Modification timestamp: 2023-08-14 12:11:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020314-1.c

#include <stdio.h>
#include <stdlib.h>

void f(void *a, double y)
{
}

double g(double a, double b, double c, double d)
{
  double x, y, z;
  void *p;

  x = a + b;
  y = c * d;

  p = alloca(16);

  f(p, y);
  z = x * y * a;

  return z + b;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <a> <b> <c> <d>\n", argv[0]);
    return 1;
  }

  double a = atof(argv[1]);
  double b = atof(argv[2]);
  double c = atof(argv[3]);
  double d = atof(argv[4]);

  if (g(a, b, c, d) != 0.0)
    abort();

  if (a != 1.0 || b != 0.0 || c != 10.0 || d != 0.0)
    abort();

  return 0;
}
