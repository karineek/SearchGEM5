// Modification timestamp: 2023-08-14 14:40:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nest-stdar-1.c
#include <stdarg.h>

main ()
{
  double f (int x, ...)
    {
      va_list args;
      double a;

      va_start (args, x);
      a = va_arg (args, double);
      va_end (args);
      return a;
    }

  if (f (1, (double)1) != 1.0)
    abort ();
  exit (0);
}
