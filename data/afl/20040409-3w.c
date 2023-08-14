// Modification timestamp: 2023-08-14 12:54:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040409-3w.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort ();

int test2(int x)
{
  return ~(x + INT_MIN);
}

int test3(int x)
{
  return ~(x - INT_MIN);
}

int test5(int x)
{
  int y = INT_MIN;
  return ~(x + y);
}

int test6(int x)
{
  int y = INT_MIN;
  return ~(x - y);
}

void test(int a, int b)
{
  if (test2(a) != b)
    abort();
  if (test3(a) != b)
    abort();
  if (test5(a) != b)
    abort();
  if (test6(a) != b)
    abort();
}

int main(int argc, char *argv[])
{
#if INT_MAX == 2147483647
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  test(atoi(argv[1]), atoi(argv[2]));
#endif

#if INT_MAX == 32767
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  test(atoi(argv[1]), atoi(argv[2]));
#endif

  return 0;
}
