// Modification timestamp: 2023-08-14 17:00:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-4.c

#include <stdarg.h>
#include <stdlib.h>

typedef struct {
  char a[32];
} big;

void f(big x, char *s, ...) {
  va_list ap;

  if (x.a[0] != 'a' || x.a[1] != 'b' || x.a[2] != 'c')
    abort();
  va_start(ap, s);
  if (va_arg(ap, int) != 42)
    abort();
  if (va_arg(ap, int) != 'x')
    abort();
  if (va_arg(ap, int) != 0)
    abort();
  va_end(ap);
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  static big x = { "abc" };

  f(x, "", 42, 'x', 0);
  exit(0);
}

