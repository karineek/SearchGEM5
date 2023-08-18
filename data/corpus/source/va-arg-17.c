// Modification timestamp: 2023-08-14 16:57:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-17.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef double TYPE;

void vafunction(int argc, char *argv[], char *dummy, ...)
{
  va_list ap;

  va_start(ap, dummy);
  if (va_arg(ap, TYPE) != atof(argv[1]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[2]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[3]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[4]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[5]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[6]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[7]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[8]))
    abort();
  if (va_arg(ap, TYPE) != atof(argv[9]))
    abort();
  va_end(ap);
}

int main(int argc, char *argv[])
{
  if (argc != 10) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7> <value8> <value9>\n", argv[0]);
    return 1;
  }

  vafunction(argc, argv, "", atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]),
             atof(argv[5]), atof(argv[6]), atof(argv[7]), atof(argv[8]), atof(argv[9]));
             
  return 0;
}

