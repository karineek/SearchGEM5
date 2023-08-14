// Modification timestamp: 2023-08-14 17:00:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-26.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

double f (float f1, float f2, float f3, float f4,
	  float f5, float f6, ...)
{
  va_list ap;
  double d;

  va_start (ap, f6);
  d = va_arg (ap, double);
  va_end (ap);
  return d;
}

int main (int argc, char *argv[])
{
  if (argc < 8) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7>\n", argv[0]);
    return 1;
  }

  float f1 = atof(argv[1]);
  float f2 = atof(argv[2]);
  float f3 = atof(argv[3]);
  float f4 = atof(argv[4]);
  float f5 = atof(argv[5]);
  float f6 = atof(argv[6]);
  double d = atof(argv[7]);

  if (f(f1, f2, f3, f4, f5, f6) != d)
    abort ();
  
  return 0;
}
