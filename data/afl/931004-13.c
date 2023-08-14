// Modification timestamp: 2023-08-14 13:37:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-13.c

#include <stdio.h>
#include <stdlib.h>

struct tiny
{
  char c;
  char d;
  char e;
  char f;
};

void f(int n, struct tiny x, struct tiny y, struct tiny z, long l)
{
  if (x.c != 10)
    abort();
  if (x.d != 20)
    abort();
  if (x.e != 30)
    abort();
  if (x.f != 40)
    abort();

  if (y.c != 11)
    abort();
  if (y.d != 21)
    abort();
  if (y.e != 31)
    abort();
  if (y.f != 41)
    abort();

  if (z.c != 12)
    abort();
  if (z.d != 22)
    abort();
  if (z.e != 32)
    abort();
  if (z.f != 42)
    abort();

  if (l != 123)
    abort ();
}

int main(int argc, char *argv[]) {
  struct tiny x[3];
  x[0].c = argv[1][0];
  x[1].c = argv[2][0];
  x[2].c = argv[3][0];
  x[0].d = argv[4][0];
  x[1].d = argv[5][0];
  x[2].d = argv[6][0];
  x[0].e = argv[7][0];
  x[1].e = argv[8][0];
  x[2].e = argv[9][0];
  x[0].f = argv[10][0];
  x[1].f = argv[11][0];
  x[2].f = argv[12][0];
  f(3, x[0], x[1], x[2], (long) atoi(argv[13]));
  exit(0);
}
