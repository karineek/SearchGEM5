// Modification timestamp: 2023-08-14 13:02:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050316-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef int V2SI __attribute__((vector_size(8)));
typedef unsigned int V2USI __attribute__((vector_size(8)));
typedef short V2HI __attribute__((vector_size(4)));
typedef unsigned int V2UHI __attribute__((vector_size(4)));

int test1(int x)
{
  return (long long)(V2SI)0LL;
}

int test2(int x, V2SI y)
{
  return (long long)y;
}

V2SI test3(int x)
{
  return (V2SI)(long long)(int)(V2HI)0;
}

V2SI test4(int x, V2HI y)
{
  return (V2SI)(long long)(int)y;
}

V2SI test5(int x, V2USI z)
{
  return (V2SI)z;
}

int main(int argc, char *argv[])
{
  if (sizeof(short) != 2 || sizeof(int) != 4 || sizeof(long long) != 8)
    return 0;

  if (test1(0) != 0)
    abort();

  V2SI x = {2, 2};
  if (test2(0, x) != 2)
    abort();

  union {
    V2SI x;
    int y[2];
    V2USI z;
    long long l;
  } u;
  u.x = test3(0);
  if (u.y[0] != 0 || u.y[1] != 0)
    abort();

  V2HI y = {4, 4};
  union {
    V2SI x;
    long long y;
  } v;
  v.x = test4(0, y);
  if (v.y != 0x40004)
    abort();

  V2USI z = {6, 6};
  u.x = test5(0, z);
  if (u.y[0] != 6 || u.y[1] != 6)
    abort();
  return 0;
}
