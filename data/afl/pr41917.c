// Modification timestamp: 2023-08-14 15:08:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41917.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int a = atoi(argv[1]);
  unsigned int b, c, d;

  if (sizeof(int) != 4 || (int)0xc7d24b5e > 0)
    return 0;

  c = 0xc7d24b5e;
  d = a | -2;
  b = (d == 0) ? c : (c % d);
  if (b != c)
    abort();

  return 0;
}

