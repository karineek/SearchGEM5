// Modification timestamp: 2023-08-14 14:51:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr28982b.c

#include <stdio.h>

#define NITER 4
#define NVARS 20
#define MULTI(X) \
  X( 0), X( 1), X( 2), X( 3), X( 4), X( 5), X( 6), X( 7), X( 8), X( 9), \
  X(10), X(11), X(12), X(13), X(14), X(15), X(16), X(17), X(18), X(19)

#define DECLAREI(INDEX) int inc##INDEX = atoi(argv[INDEX + 1])
#define DECLAREF(INDEX) *ptr##INDEX = atof(argv[INDEX + NVARS + 1]), result##INDEX = 0
#define LOOP(INDEX) result##INDEX += *ptr##INDEX, ptr##INDEX += inc##INDEX
#define COPYOUT(INDEX) results[INDEX] = result##INDEX

void bar() {
  // do nothing
}

int main(int argc, char *argv[]) {
  int i;

  if (argc != 2 * NVARS + 1) {
    printf("Usage: %s <value1> <value2> ... <value%d>\n", argv[0], NVARS);
    return 1;
  }

  float *ptrs[NVARS];
  float results[NVARS];
  int incs[NVARS];

  for (i = 0; i < NVARS; i++)
    ptrs[i] = input + i, incs[i] = i;
  for (i = 0; i < NITER * NVARS; i++)
    input[i] = i;
  foo (NITER);
  for (i = 0; i < NVARS; i++)
    if (results[i] != i * NITER * (NITER + 1) / 2)
      return 1;
  return 0;
}
