// Modification timestamp: 2023-08-14 13:37:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-12.c


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct tiny
{
  char c;
  char d;
  char e;
};

void f(int n, ...)
{
  struct tiny x;
  int i;

  va_list ap;
  va_start(ap, n);
  for (i = 0; i < n; i++)
  {
    x = va_arg(ap, struct tiny);
    if (x.c != i + 10)
      abort();
    if (x.d != i + 20)
      abort();
    if (x.e != i + 30)
      abort();
  }
  {
    long x = va_arg(ap, long);
    if (x != 123)
      abort();
  }
  va_end(ap);
}

int main(int argc, char *argv[])
{
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
  f(3, x[0], x[1], x[2], (long) 123);
  exit(0);
}


Note: The program assumes that there are at least 10 command line arguments provided.