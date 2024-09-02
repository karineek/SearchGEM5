// Modification timestamp: 2023-08-14 17:00:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-6.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void f(int n, ...) {
  va_list args;
  va_start(args, n);

  if (va_arg(args, int) != atoi(argv[1])) abort ();
  if (va_arg(args, long long) != atoll(argv[2])) abort ();
  if (va_arg(args, int) != atoi(argv[3])) abort ();
  if (va_arg(args, long double) != strtold(argv[4], NULL)) abort ();
  if (va_arg(args, int) != atoi(argv[5])) abort ();
  if (va_arg(args, int) != atoi(argv[6])) abort ();
  if (va_arg(args, long long) != atoll(argv[7])) abort ();
  if (va_arg(args, int) != atoi(argv[8])) abort ();
  if (va_arg(args, double) != atof(argv[9])) abort ();

  va_end(args);
}

int main(int argc, char *argv[]) {
  if (argc != 10) {
    printf("Usage: %s <value1> <value2> <value3> <value4> <value5> <value6> <value7> <value8> <value9>\n", argv[0]);
    return 1;
  }

  f(4, atoi(argv[1]), atoll(argv[2]), atoi(argv[3]), strtold(argv[4], NULL), atoi(argv[5]), atoi(argv[6]), atoll(argv[7]), atoi(argv[8]), atof(argv[9]));
  exit(0);
}
