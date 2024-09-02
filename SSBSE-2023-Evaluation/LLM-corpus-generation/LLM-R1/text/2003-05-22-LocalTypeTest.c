// Modification timestamp: 2023-08-14 17:32:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-22-LocalTypeTest.c
#include <stdio.h>

struct sometimes {
  short offset; short bit;
  short live_length; short calls_crossed;
} Y;

int main() {
  int X;
  {
    struct sometimes { int X, Y; } S;
    S.X = 1;
    X = S.X;
  }
  {
    struct sometimes { signed char X; } S;
    S.X = -1;
    X += S.X;
  }
  X += Y.offset;

  printf("Result is %d\n", X);
  return X;
}
