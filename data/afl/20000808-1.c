c
// Modification timestamp: 2023-08-10 16:43:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/7zip/20000808-1.c

#include <stdlib.h>

typedef struct {
  long int p_x, p_y;
} Point;

void bar() {
}

void f(Point p0, Point p1, Point p2, Point p3, Point p4, Point p5) {
  if (p0.p_x != 0 || p0.p_y != 1 || p1.p_x != -1 || p1.p_y != 0 || p2.p_x != 1 ||
      p2.p_y != -1 || p3.p_x != -1 || p3.p_y != 1 || p4.p_x != 0 ||
      p4.p_y != -1 || p5.p_x != 1 || p5.p_y != 0)
    abort();
}

void foo() {
  Point p0, p1, p2, p3, p4, p5;

  bar();

  p0.p_x = 0;
  p0.p_y = 1;

  p1.p_x = -1;
  p1.p_y = 0;

  p2.p_x = 1;
  p2.p_y = -1;

  p3.p_x = -1;
  p3.p_y = 1;

  p4.p_x = 0;
  p4.p_y = -1;

  p5.p_x = 1;
  p5.p_y = 0;

  f(p0, p1, p2, p3, p4, p5);
}

int main(int argc, char *argv[]) {
  foo();
  exit(0);
}
