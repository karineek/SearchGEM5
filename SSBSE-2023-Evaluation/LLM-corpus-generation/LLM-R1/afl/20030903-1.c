// Modification timestamp: 2023-08-14 12:48:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030903-1.c

#include <stdio.h>
#include <stdlib.h>

enum X { X1 = 1, X2, X3, X4 };

static void y(int);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  enum X test = atoi(argv[1]);

  switch (test) {
    case X1: y(1); break;
    case X2: y(2); break;
    case X3: y(3); break;
    case X4: y(4); break;
  }

  return 0;
}

static void y(int x) {
  abort();
}
