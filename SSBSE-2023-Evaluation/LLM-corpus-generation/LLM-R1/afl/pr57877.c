// Modification timestamp: 2023-08-14 15:29:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57877.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a, b, *c = &b, e, f = 6, g, h;
short d;

static unsigned char foo(unsigned long long p1, int *p2) {
  for (; g <= 0; g++) {
    short *i = &d;
    int *j = &e;
    h = *c;
    *i = h;
    *j = (*i == *p2) < p1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  foo(arg1, &a);
  if (e != 1)
    abort();
  return 0;
}
