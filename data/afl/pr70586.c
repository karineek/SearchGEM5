// Modification timestamp: 2023-08-14 15:50:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70586.c

#include <stdio.h>
#include <stdlib.h>

int a, e, f;
short b, c, d;

int foo(int x, int y) {
  return (y == 0 || (x && y == 1)) ? x : x % y;
}

static short bar(void) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = foo(c, f);
  f = foo(d, atoi(argv[1]));
  int g = foo(b, c);
  int h = foo(g > 0, c);
  c = (3 >= h ^ 7) <= foo(i, c);
  if (foo(e, atoi(argv[2])))
    return a;
  return 0;
}

int main(int argc, char *argv[]) {
  bar();
  return 0;
}
