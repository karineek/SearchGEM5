// Modification timestamp: 2023-08-14 15:35:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58662.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a, c, d;
volatile int b;

static int foo(int p1, short p2) {
  return p1 / p2;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int e;
  int x = atoi(argv[1]);

  d = foo(x == 0, (0, 35536));
  e = d % 14;
  b = e && c;
  if (b != 0)
    abort();
  return 0;
}
