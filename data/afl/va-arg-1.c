// Modification timestamp: 2023-08-14 16:54:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-1.c

#include <stdarg.h>
#include <stdlib.h>

typedef unsigned long L;

void f(L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...) {
  va_list select;
  va_start(select, p8);

  if (va_arg(select, L) != 10)
    abort();
  if (va_arg(select, L) != 11)
    abort();
  if (va_arg(select, L) != 0)
    abort();

  va_end(select);
}

int main(int argc, char *argv[]) {
  f(1L, 2L, 3L, 4L, 5L, 6L, 7L, 8L, 9L, atoi(argv[1]), atoi(argv[2]), 0L);
  exit(0);
}

