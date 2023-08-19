// Modification timestamp: 2023-08-14 13:03:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050607-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef int V2SI __attribute__ ((vector_size (8)));

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

#if (__INT_MAX__ == 2147483647) \
    && (__LONG_LONG_MAX__ == 9223372036854775807LL)
  if (((int)(long long)(V2SI){ atoi(argv[1]), atoi(argv[2]) }) != 2)
    abort();
#endif

  return 0;
}
