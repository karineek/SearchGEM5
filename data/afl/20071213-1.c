// Modification timestamp: 2023-08-14 13:12:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071213-1.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

void h (int x, va_list ap) {
  switch (x) {
    case 1:
      if (va_arg (ap, int) != 3 || va_arg (ap, int) != 4)
        abort ();
      return;
    case 5:
      if (va_arg (ap, int) != 9 || va_arg (ap, int) != 10)
        abort ();
      return;
    default:
      abort ();
  }
}

void f1 (int i, long long int j, ...) {
  va_list ap;
  va_start (ap, j);
  h (i, ap);
  if (i != 1 || j != 2)
    abort ();
  va_end (ap);
}

void f2 (int i, int j, int k, long long int l, ...) {
  va_list ap;
  va_start (ap, l);
  h (i, ap);
  if (i != 5 || j != 6 || k != 7 || l != 8)
    abort ();
  va_end (ap);
}

int main (int argc, char *argv[]) {
  f1 (atoi(argv[1]), atoll(argv[2]), atoi(argv[3]), atoi(argv[4]));
  f2 (atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoll(argv[8]), atoi(argv[9]), atoi(argv[10]));
  return 0;
}
