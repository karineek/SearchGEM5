// Modification timestamp: 2023-08-14 13:04:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050713-1.c
#include <stdio.h>
#include <stdlib.h>

struct S
{
  int a, b, c;
};

int foo2(struct S x, struct S y)
{
  if (x.a != 3 || x.b != 4 || x.c != 5)
    abort();
  if (y.a != 6 || y.b != 7 || y.c != 8)
    abort();
  return 0;
}

int foo3(struct S x, struct S y, struct S z)
{
  foo2(x, y);
  if (z.a != 9 || z.b != 10 || z.c != 11)
    abort();
  return 0;
}

int bar2(struct S x, struct S y)
{
  return foo2(y, x);
}

int bar3(struct S x, struct S y, struct S z)
{
  return foo3(y, x, z);
}

int baz3(struct S x, struct S y, struct S z)
{
  return foo3(y, z, x);
}

int main(int argc, char *argv[])
{
  if (argc != 10)
  {
    printf("Usage: %s <a.a> <a.b> <a.c> <b.a> <b.b> <b.c> <c.a> <c.b> <c.c>\n", argv[0]);
    return 1;
  }

  struct S a = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
  struct S b = {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
  struct S c = {atoi(argv[7]), atoi(argv[8]), atoi(argv[9])};

  bar2(b, a);
  bar3(b, a, c);
  baz3(c, a, b);
  return 0;
}