// Modification timestamp: 2023-08-14 17:00:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-5.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void va_double(int n, ...) {
  va_list args;
  va_start(args, n);

  if (va_arg(args, double) != 3.141592)
    abort();
  if (va_arg(args, double) != 2.71827)
    abort();
  if (va_arg(args, double) != 2.2360679)
    abort();
  if (va_arg(args, double) != 2.1474836)
    abort();

  va_end(args);
}

void va_long_double(int n, ...) {
  va_list args;
  va_start(args, n);

  if (va_arg(args, long double) != 3.141592L)
    abort();
  if (va_arg(args, long double) != 2.71827L)
    abort();
  if (va_arg(args, long double) != 2.2360679L)
    abort();
  if (va_arg(args, long double) != 2.1474836L)
    abort();

  va_end(args);
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  va_double(4, atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4]));
  va_long_double(4, atof(argv[5]), atof(argv[6]), atof(argv[7]), atof(argv[8]));
  exit(0);
}
