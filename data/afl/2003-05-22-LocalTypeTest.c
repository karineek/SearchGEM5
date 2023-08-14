c
// Modification timestamp: 2023-08-10 15:53:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/PR2003-05-22-LocalTypeTest.c

#include <stdio.h>

struct sometimes {
  short offset;
  short bit;
  short live_length;
  short calls_crossed;
} Y;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int X;
  {
    struct sometimes { int X, Y; } S;
    S.X = atoi(argv[1]);
    X = S.X;
  }
  {
    struct sometimes { signed char X; } S;
    S.X = atoi(argv[1]);
    X += S.X;
  }
  X += Y.offset;

  printf("Result is %d\n", X);
  return X;
}
