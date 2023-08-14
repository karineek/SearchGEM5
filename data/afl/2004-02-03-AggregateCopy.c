
// Modification timestamp: 2023-08-10 15:55:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/CMakeFiles/2004-02-03-AggregateCopy.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int X;
} agg;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  agg A;
  A.X = arg;
  agg B, C;
  B = C = A;

  printf("%d, %d, %d\n", A.X, B.X, C.X);
  return 0;
}
