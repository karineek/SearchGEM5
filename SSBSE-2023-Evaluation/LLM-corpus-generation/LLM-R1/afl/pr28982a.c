// Modification timestamp: 2023-08-14 14:51:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr28982a.c

#include <stdio.h>
#include <string.h>

#define NITER 4
#define NVARS 20
#define MULTI(X) \
  X( 0), X( 1), X( 2), X( 3), X( 4), X( 5), X( 6), X( 7), X( 8), X( 9), \
  X(10), X(11), X(12), X(13), X(14), X(15), X(16), X(17), X(18), X(19)

#define DECLAREI(INDEX) int inc##INDEX = atoi(argv[INDEX + 1])
#define DECLAREF(INDEX) \
  float *ptr##INDEX = (float*)argv[INDEX + NVARS + 1], result##INDEX = 0
#define LOOP(INDEX) result##INDEX += *ptr##INDEX, ptr##INDEX += inc##INDEX
#define COPYOUT(INDEX) results[INDEX] = result##INDEX

float results[NVARS];
int incs[NVARS];

void foo(int n) {
  int MULTI(DECLAREI);
  float MULTI(DECLAREF);
  while (n--)
    MULTI(LOOP);
  MULTI(COPYOUT);
}

int main(int argc, char *argv[]) {
  if (argc != NVARS * 2 + 1) {
    printf("Invalid arguments\n");
    return 1;
  }

  for (int i = 0; i < NVARS; i++) {
    ptrs[i] = (float*)argv[i + 1];
    incs[i] = i;
  }

  foo(NITER);

  for (int i = 0; i < NVARS; i++) {
    if (results[i] != i * NITER * (NITER + 1) / 2) {
      printf("Mismatch at index %d\n", i);
      return 1;
    }
  }

  return 0;
}
