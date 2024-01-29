// Modification timestamp: 2023-08-14 16:56:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-15.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void vafunction(char *dummy, ...)
{
  double darg;
  int iarg;
  int flag = 0;
  int i;
  va_list ap;

  va_start(ap, dummy);
  for (i = 1; i <= 18; i++, flag++)
  {
    if (flag & 1)
    {
      darg = va_arg(ap, double);
      if (darg != (double)i)
        abort();
    }
    else
    {
      iarg = va_arg(ap, int);
      if (iarg != i)
        abort();
    }
  }
  va_end(ap);
}

int main(int argc, char *argv[])
{
  if (argc != 37)
  {
    printf("Usage: %s <value1> <value2> ... <value18>\n", argv[0]);
    return 1;
  }

  int values[18];
  for (int i = 0; i < 18; i++)
  {
    values[i] = atoi(argv[i + 1]);
  }

  vafunction("", values[0], (double)values[1], values[2], (double)values[3], values[4], (double)values[5], values[6], (double)values[7], values[8], (double)values[9], values[10], (double)values[11], values[12], (double)values[13], values[14], (double)values[15], values[16], (double)values[17]);
  exit(0);
  return 0;
}

Note: The program now expects 37 command line arguments to be passed. The first argument is the program name, and the remaining 36 arguments should be the values to be passed to the `vafunction` function.