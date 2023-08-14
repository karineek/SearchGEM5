// Modification timestamp: 2023-08-14 14:40:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-1.c

#include <stdio.h>
#include <stdlib.h>

int g(int a, int b, int (*gi)(int, int)) {
  if ((*gi)(a, b))
    return a;
  else
    return b;
}

int f() {
  int i, j;
  int f2(int a, int b) {
    return a > b;
  }

  if (g(atoi(argv[1]), atoi(argv[2]), f2) != atoi(argv[3])) {
    printf("Error: g(1, 2, f2) != %s\n", argv[3]);
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value> <value> <value>\n", argv[0]);
    return 1;
  }

  f();
  return 0;
}
