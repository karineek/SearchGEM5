// Modification timestamp: 2023-08-14 13:57:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991202-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, y;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);
  y = x;
  do {
    x = y;
    y = 2 * y;
  } while (!((y - x) >= 20));

  exit(0);
}
