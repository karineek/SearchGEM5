// Modification timestamp: 2023-08-14 16:56:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-16.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef double TYPE;

void vafunction (TYPE dummy1, TYPE dummy2, ...) {
  va_list ap;

  va_start(ap, dummy2);
  if (dummy1 != atof(argv[1]))
    abort();
  if (dummy2 != atof(argv[2]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[3]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[4]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[5]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[6]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[7]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[8]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[9]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[10]))
    abort();
  if (va_arg (ap, TYPE) != atof(argv[11]))
    abort();
  va_end(ap);
}

int main(int argc, char *argv[]) {
  if (argc != 12) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7> <value8> <value9> <value10> <value11>\n", argv[0]);
    return 1;
  }

  vafunction(atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]), atof(argv[5]), atof(argv[6]), atof(argv[7]), atof(argv[8]), atof(argv[9]), atof(argv[10]), atof(argv[11]));
  exit(0);
  return 0;
}
