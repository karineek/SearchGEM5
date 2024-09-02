// Modification timestamp: 2023-08-14 13:05:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051215-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

__attribute__ ((noinline)) int foo(int x, int y, int *z) {
  int a, b, c, d;

  a = b = 0;
  for (d = 0; d < y; d++) {
    if (z) b = d * *z;
    for (c = 0; c < x; c++) a += b;
  }

  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <x> <y> <z>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  int *z = atoi(argv[3]);
  
  if (foo(x, y, z) != 0) abort();
  return 0;
}
