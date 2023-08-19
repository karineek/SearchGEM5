// Modification timestamp: 2023-08-14 12:38:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021120-2.c

#include <stdio.h>
#include <stdlib.h>

int g1, g2;

void foo(int x) {
  int y;

  if (x)
    y = atoi(argv[1]);
  else
    y = atoi(argv[1]);
  
  g1 = 7930 / y;
  g2 = 7930 / x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo(atoi(argv[1]));
  if (g1 != 10 || g2 != 10)
    abort();
  exit(0);
}
