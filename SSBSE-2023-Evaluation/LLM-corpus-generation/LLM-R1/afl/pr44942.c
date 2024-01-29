// Modification timestamp: 2023-08-14 15:14:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44942.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void test1 (int a, int b, int c, int d, int e, int f, int g, long double h, ...) {
  int i;
  va_list ap;

  va_start (ap, h);
  i = va_arg (ap, int);
  if (i != 1234)
    __builtin_abort ();
  va_end (ap);
}

void test2 (int a, int b, int c, int d, int e, int f, int g, long double h, int i,
       long double j, int k, long double l, int m, long double n, ...) {
  int o;
  va_list ap;

  va_start (ap, n);
  o = va_arg (ap, int);
  if (o != 1234)
    __builtin_abort ();
  va_end (ap);
}

void test3 (double a, double b, double c, double d, double e, double f,
       double g, long double h, ...) {
  double i;
  va_list ap;

  va_start (ap, h);
  i = va_arg (ap, double);
  if (i != 1234.0)
    __builtin_abort ();
  va_end (ap);
}

void test4 (double a, double b, double c, double d, double e, double f, double g,
       long double h, double i, long double j, double k, long double l,
       double m, long double n, ...) {
  double o;
  va_list ap;

  va_start (ap, n);
  o = va_arg (ap, double);
  if (o != 1234.0)
    __builtin_abort ();
  va_end (ap);
}

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  double arg2 = atof(argv[2]);
  long double arg3 = atof(argv[3]);

  test1(0, 0, 0, 0, 0, 0, 0, 0.0L, arg1);
  test2(0, 0, 0, 0, 0, 0, 0, 0.0L, 0, 0.0L, 0, 0.0L, 0, 0.0L, arg1);
  test3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, arg2);
  test4(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 0.0, 0.0L,
     0.0, 0.0L, 0.0, 0.0L, arg2);

  return 0;
}
