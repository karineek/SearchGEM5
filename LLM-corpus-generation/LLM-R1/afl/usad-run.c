// Modification timestamp: 2023-08-14 16:54:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/usad-run.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();
extern int abs(int __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));

static int foo(unsigned char *w, int i, unsigned char *x, int j) {
  int tot = 0;
  for (int a = 0; a < 16; a++) {
    for (int b = 0; b < 16; b++)
      tot += abs(w[b] - x[b]);
    w += i;
    x += j;
  }
  return tot;
}

void bar(unsigned char *w, unsigned char *x, int i, int *result) {
  *result = foo(w, 16, x, i);
}

int main(int argc, char *argv[]) {
  unsigned char m[256];
  unsigned char n[256];
  int sum, i;

  for (i = 0; i < 256; ++i)
    if (i % 2 == 0) {
      m[i] = (i % 8) * 2 + 1;
      n[i] = -(i % 8);
    } else {
      m[i] = -((i % 8) * 2 + 2);
      n[i] = -((i % 8) >> 1);
    }

  if (argc < 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  bar(m, n, arg1, &sum);

  if (sum != 32384)
    abort();

  return 0;
}
