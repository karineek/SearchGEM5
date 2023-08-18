// Modification timestamp: 2023-08-14 14:51:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr28403.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
int global;

int __attribute__((noinline))
foo(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8)
{
  global = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;
}

ull __attribute__((noinline))
bar(ull x, int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8)
{
  foo(x1, x2, x3, x4, x5, x6, x7, x8);
  return x >> global;
}

int main(int argc, char *argv[])
{
  if (argc != 10)
  {
    printf("Usage: %s <x1> <x2> <x3> <x4> <x5> <x6> <x7> <x8>\n", argv[0]);
    return 1;
  }

  ull x = strtoull(argv[9], NULL, 16);
  int x1 = atoi(argv[1]);
  int x2 = atoi(argv[2]);
  int x3 = atoi(argv[3]);
  int x4 = atoi(argv[4]);
  int x5 = atoi(argv[5]);
  int x6 = atoi(argv[6]);
  int x7 = atoi(argv[7]);
  int x8 = atoi(argv[8]);

  if (bar(x, x1, x2, x3, x4, x5, x6, x7, x8) != (x >> 18))
    abort();

  exit(0);
}
