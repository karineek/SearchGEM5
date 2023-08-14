
// Modification timestamp: 2023-08-10 15:55:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/ALAC/2004-08-12-InlinerAndAllocas.c

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#include <stdlib.h>
#else
#include <alloca.h>
#endif
#include <stdio.h>

static int Callee(int i) {
  if (i != 0) {
    char *X = alloca(1000);
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
  for (i = 0; i < 10000; ++i)
    j += Callee(i);
  printf("%d\n", j);
  return 0;
}
