// Modification timestamp: 2023-08-14 16:05:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr91137.c

#include <stdio.h>
#include <stdlib.h>

long long a;
unsigned b;
int c[70];
int d[70][70];
int e;

__attribute__ ((noinline)) void f(long long *g, int p2) {
  *g = p2;
}

__attribute__ ((noinline)) void fn2(unsigned b, int c[], int d[][70], int e) {
  for (int j = 0; j < 70; j++) {
    for (int i = 0; i < 70; i++) {
      if (b)
        c[i] = 0;
      for (int l = 0; l < 70; l++)
        d[i][1] = d[l][i];
    }
    for (int k = 0; k < 70; k++)
      e = c[0];
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  b = atoi(argv[1]);
  for (int j = 0; j < 70; ++j)
    c[j] = 2075593088;
  fn2(b, c, d, e);
  f(&a, e);
  if (a)
    __builtin_abort();
  return 0;
}
