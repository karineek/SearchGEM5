// Modification timestamp: 2023-08-14 15:47:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68624.c

#include <stdio.h>
#include <stdlib.h>

int b, c, d, e = 1, f, g, h, j;

static int fn1(int c, int b, int d, int e, int f, int g, int h, int j) {
  int a = c;
  if (h)
    return 9;
  g = (c || b) % e;
  if ((g || f) && b)
    return 9;
  e = d;
  for (c = 0; c > -4; c--)
    ;
  if (d)
    c--;
  j = c;
  return d;
}

int main(int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <b> <c> <d> <e> <f> <g> <h> <j>\n", argv[0]);
    return 1;
  }

  b = atoi(argv[1]);
  c = atoi(argv[2]);
  d = atoi(argv[3]);
  e = atoi(argv[4]);
  f = atoi(argv[5]);
  g = atoi(argv[6]);
  h = atoi(argv[7]);
  j = atoi(argv[8]);

  fn1(c, b, d, e, f, g, h, j);

  if (c != -4)
    __builtin_abort();

  return 0;
}

