// Modification timestamp: 2023-08-14 15:28:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57861.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
short a = 1, f;
int b, c, d, *g = &b, h, i, j;
unsigned int e;

static int foo(char p) {
  int k;
  for (c = 0; c < 2; c++) {
    i = (j = 0) || p;
    k = i * p;
    if (e < k) {
      short *l = &f;
      a = d && h;
      *l = 0;
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  *g = foo(atoi(argv[1]));
  if (a != 0)
    abort();
  return 0;
}
