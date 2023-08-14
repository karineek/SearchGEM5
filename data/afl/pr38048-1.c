// Modification timestamp: 2023-08-14 15:01:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38048-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int (*a)[1]) {
  int det = 0;
  int i;
  a[0][0] = 1;
  a[1][0] = 2;
  for (i = 0; i < 2; ++i)
    det += a[i][0];
  return det;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int mat[2][1];
  int (*a)[1] = mat;
  int det = foo(a);

  if (det != atoi(argv[1])) {
    abort();
  }

  return 0;
}
