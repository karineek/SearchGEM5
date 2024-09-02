// Modification timestamp: 2023-08-14 16:56:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-11.c

#include <stdarg.h>
#include <stdlib.h>

static int foo (int a, ...) {
  va_list va;
  int i, res;

  va_start (va, a);

  for (i = 0; i < 4; ++i)
    (void) va_arg (va, int);

  res = va_arg (va, int);

  va_end (va);

  return res;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo(atoi(argv[1]), 4, 3, 2, 1, 0))
    abort();

  exit(0);
}
