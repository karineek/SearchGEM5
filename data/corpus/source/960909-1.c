// Modification timestamp: 2023-08-14 13:47:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960909-1.c

#include <stdio.h>
#include <stdlib.h>

int ffs(int x) {
  int bit, mask;

  if (x == 0)
    return 0;

  for (bit = 1, mask = 1; !(x & mask); bit++, mask <<= 1)
    ;

  return bit;
}

void f(int x) {
  int y;
  y = ffs(x) - 1;
  if (y < 0)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  f(x);
  exit(0);
}
