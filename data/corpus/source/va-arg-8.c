// Modification timestamp: 2023-08-14 17:01:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-8.c

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

#if __LLONG_MAX__ == 9223372036854775807LL

typedef long long int INT64;

inline void debug(int i1, int i2, int i3, int i4, int i5,
                  int i6, int i7, int i8, int i9, ...) {
  va_list ap;

  va_start(ap, i9);

  if (va_arg(ap, int) != 10)
    abort();
  if (va_arg(ap, INT64) != 0x123400005678LL)
    abort();

  va_end(ap);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  debug(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, x);

  exit(0);
}

#else

int main(void) {
  exit(0);
}

#endif /* long long 64 bits */
