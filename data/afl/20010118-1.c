// Modification timestamp: 2023-08-14 11:56:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010118-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a, b, c, d, e, f;
} A;

void foo(A *v, int w, int x, int *y, int *z)
{
}

void bar(A *v, int x, int y, int w, int h)
{
  if (v->a != x || v->b != y) {
    int oldw = w;
    int oldh = h;
    int e = v->e;
    int f = v->f;
    int dx, dy;
    foo(v, 0, 0, &w, &h);
    dx = (oldw - w) * (double)e / 2.0;
    dy = (oldh - h) * (double)f / 2.0;
    x += dx;
    y += dy;
    v->a = x;
    v->b = y;
    v->c = w;
    v->d = h;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  A w = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
  bar(&w, atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]));
  if (w.d != atoi(argv[11]))
    abort();
  exit(0);
}
