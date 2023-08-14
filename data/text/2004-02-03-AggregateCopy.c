
// Modification timestamp: 2023-08-10 15:55:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/CMakeFiles/2004-02-03-AggregateCopy.c

#include <stdio.h>

typedef struct {
  int X;
} agg;

int main() {
  agg A;
  A.X = 123;
  agg B, C;
  B = C = A;

  printf("%d, %d, %d\n", A.X, B.X, C.X);
  return 0;
}
