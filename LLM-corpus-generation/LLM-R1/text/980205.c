// Modification timestamp: 2023-08-14 13:48:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980205.c
#include <stdarg.h>

void fdouble (double one, ...)
{
  double value;
  va_list ap;

  va_start (ap, one);
  value = va_arg (ap, double);
  va_end (ap);

  if (one != 1.0 || value != 2.0)
    abort ();
}

int main ()
{
  fdouble (1.0, 2.0);
  exit (0);
}
