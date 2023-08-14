// Modification timestamp: 2023-08-14 17:32:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2004-02-03-AggregateCopy.c

#include <stdio.h>

typedef struct {
  int X;
} agg;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  agg A;  A.X = atoi(argv[1]);
  agg B, C;
  B = C = A;

  printf("%d, %d, %d\n", A.X, B.X, C.X);
  return 0;
}
