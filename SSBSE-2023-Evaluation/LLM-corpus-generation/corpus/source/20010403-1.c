// Modification timestamp: 2023-08-14 11:58:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010403-1.c

#include <stdio.h>
#include <stdlib.h>

void b(int *);
void c(int, int);
void d(int);

int e;

void a(int x, int y)
{
  int f = x ? e : 0;
  int z = y;

  b(&y);
  c(z, y);
  d(f);
}

void b(int *y)
{
  (*y)++;
}

void c(int x, int y)
{
  if (x == y)
    abort ();
}

void d(int x)
{
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  a(x, y);
  exit(0);
}
