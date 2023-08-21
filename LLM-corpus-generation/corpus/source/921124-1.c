// Modification timestamp: 2023-08-14 13:31:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921124-1.c

#include <stdio.h>
#include <stdlib.h>

double f(int x, double d1, double d2, double d3) {
  return x;
}

void g(char *b, char *s, double x, double y, int i, int j) {
  if (x != 1.0 || y != 2.0 || i != 3 || j != 4)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  g("", "", 1.0, 2.0, f(3, 0.0, 0.0, 0.0), f(4, 0.0, 0.0, 0.0));
  exit(0);
}
