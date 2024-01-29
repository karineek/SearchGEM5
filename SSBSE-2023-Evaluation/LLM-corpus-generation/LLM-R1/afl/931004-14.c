// Modification timestamp: 2023-08-14 13:37:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-14.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct tiny
{
  char c;
  char d;
  char e;
  char f;
};

void f (int n, ...)
{
  struct tiny x;
  int i;

  va_list ap;
  va_start (ap,n);
  for (i = 0; i < n; i++)
    {
      x = va_arg (ap,struct tiny);
      if (x.c != i + 10)
        abort();
      if (x.d != i + 20)
        abort();
      if (x.e != i + 30)
        abort();
      if (x.f != i + 40)
        abort();
    }
  {
    long x = va_arg (ap, long);
    if (x != 123)
      abort();
  }
  va_end (ap);
}

int main ()
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct tiny x[3];
  x[0].c = atoi(argv[1]);
  x[1].c = atoi(argv[2]);
  x[2].c = atoi(argv[3]);
  x[0].d = atoi(argv[4]);
  x[1].d = atoi(argv[5]);
  x[2].d = atoi(argv[6]);
  x[0].e = atoi(argv[7]);
  x[1].e = atoi(argv[8]);
  x[2].e = atoi(argv[9]);
  x[0].f = atoi(argv[10]);
  x[1].f = atoi(argv[11]);
  x[2].f = atoi(argv[12]);
  f (3, x[0], x[1], x[2], (long) atoi(argv[13]));
  exit(0);
}
