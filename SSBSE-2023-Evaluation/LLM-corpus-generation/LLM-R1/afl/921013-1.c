// Modification timestamp: 2023-08-14 13:30:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921013-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int *d, float *x, float *y, int n) {
  while (n--) {
    *d++ = *x++ == *y++;
  }
}

int main(int argc, char *argv[]) {
  int r[4];
  float a[] = {5, 1, 3, 5};
  float b[] = {2, 4, 3, 0};
  int i;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);

  f(r, a, b, n);

  for (i = 0; i < n; i++) {
    if ((a[i] == b[i]) != r[i]) {
      abort();
    }
  }

  exit(0);
}
