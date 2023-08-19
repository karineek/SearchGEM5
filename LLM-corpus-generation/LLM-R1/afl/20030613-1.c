// Modification timestamp: 2023-08-14 12:46:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030613-1.c

#include <stdio.h>
#include <stdlib.h>

struct CS {
  long x;
  long y;
};

typedef struct CS COMPLEX;

COMPLEX CCID(COMPLEX x)
{
  COMPLEX a;

  a.x = x.x;
  a.y = x.y;

  return a;
}

COMPLEX CPOW(COMPLEX x, int y)
{
  COMPLEX a;
  a = x;

  while (--y > 0)
    a = CCID(a);

  return a;
}

int c5p(COMPLEX x)
{
  COMPLEX a, b;
  a = CPOW(x, 2);
  b = CCID(CPOW(a, 2));

  return (b.x == b.y);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  COMPLEX x;
  x.x = atoi(argv[1]);
  x.y = atoi(argv[2]);

  if (!c5p(x))
    abort();

  return 0;
}

