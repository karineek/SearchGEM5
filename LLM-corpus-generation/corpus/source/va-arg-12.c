// Modification timestamp: 2023-08-14 16:56:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-12.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void f(double p0, double p1, double p2, double p3, double p4, double p5, double p6, double p7, double p8, ...)
{
  va_list select;
  va_start(select, p8);

  if (va_arg(select, double) != 10.0)
    abort();
  if (va_arg(select, double) != 11.0)
    abort();
  if (va_arg(select, double) != 0.0)
    abort();

  va_end(select);
}

int main(int argc, char *argv[])
{
  if (argc != 13) {
    printf("Usage: %s <p0> <p1> <p2> <p3> <p4> <p5> <p6> <p7> <p8> <p9> <p10> <p11> <p12>\n", argv[0]);
    return 1;
  }

  double p0 = atof(argv[1]);
  double p1 = atof(argv[2]);
  double p2 = atof(argv[3]);
  double p3 = atof(argv[4]);
  double p4 = atof(argv[5]);
  double p5 = atof(argv[6]);
  double p6 = atof(argv[7]);
  double p7 = atof(argv[8]);
  double p8 = atof(argv[9]);

  f(p0, p1, p2, p3, p4, p5, p6, p7, p8, 10.0, 11.0, 0.0);
  exit(0);
}
