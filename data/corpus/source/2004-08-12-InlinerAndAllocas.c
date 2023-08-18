// Modification timestamp: 2023-08-14 17:32:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2004-08-12-InlinerAndAllocas.c

#include <stdio.h>
#include <stdlib.h>

static int Callee(int i, char *X) {
  if (i != 0) {
    sprintf(X, "%d\n", i);
    return X[0];
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i, j = 0;
  char *X = (char *)malloc(1000 * sizeof(char));
  for (i = 0; i < atoi(argv[1]); ++i)
    j += Callee(i, X);
  printf("%d\n", j);
  free(X);
  return 0;
}
