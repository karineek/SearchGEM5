// Modification timestamp: 2023-08-14 14:40:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nest-stdar-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double f (int x, ...)
{
  va_list args;
  double a;

  va_start (args, x);
  a = va_arg (args, double);
  va_end (args);
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (f(1, atof(argv[1])) != 1.0)
    abort ();
  exit(0);
}

