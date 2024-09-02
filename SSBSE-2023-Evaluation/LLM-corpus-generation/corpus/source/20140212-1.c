// Modification timestamp: 2023-08-14 13:21:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140212-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a, b, c, d = 1, e, f = 1, h, i, k;
char g, j;

void fn1(int l, int* e, int* c) {
  *e = 0;
  *c = 0;
  for (;;) {
    k = a && b;
    j = k * 54;
    g = j * 147;
    l = ~g + (long long)*e && 1;
    if (d)
      *c = l;
    else
      h = i = l * 9UL;
    if (f)
      return;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int l;
  int e = atoi(argv[1]);
  int cc;

  fn1(l, &e, &cc);
  if (cc != 1)
    abort();
  return 0;
}
