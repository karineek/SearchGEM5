// Modification timestamp: 2023-08-14 14:45:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
void foo() {} /* Necessary to trigger the original ICE.  */
void bar(char a[2][N]) { a[1][0] = N; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  N = atoi(argv[1]);
  void *x = alloca(2 * N);
  memset(x, 0, 2 * N);
  bar(x);
  if (N[(char *)x] != N) {
    abort();
  }
  exit(0);
}
