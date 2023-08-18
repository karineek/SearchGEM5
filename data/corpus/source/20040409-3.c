// Modification timestamp: 2023-08-14 12:54:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040409-3.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort ();

int test1(int x)
{
  return ~(x ^ INT_MIN);
}

unsigned int test1u(unsigned int x)
{
  return ~(x ^ (unsigned int)INT_MIN);
}

unsigned int test2u(unsigned int x)
{
  return ~(x + (unsigned int)INT_MIN);
}

unsigned int test3u(unsigned int x)
{
  return ~(x - (unsigned int)INT_MIN);
}

int test4(int x)
{
  int y = INT_MIN;
  return ~(x ^ y);
}

unsigned int test4u(unsigned int x)
{
  unsigned int y = (unsigned int)INT_MIN;
  return ~(x ^ y);
}

unsigned int test5u(unsigned int x)
{
  unsigned int y = (unsigned int)INT_MIN;
  return ~(x + y);
}

unsigned int test6u(unsigned int x)
{
  unsigned int y = (unsigned int)INT_MIN;
  return ~(x - y);
}

void test(int a, int b)
{
  if (test1(a) != b)
    abort();
  if (test4(a) != b)
    abort();
}

void testu(unsigned int a, unsigned int b)
{
  if (test1u(a) != b)
    abort();
  if (test2u(a) != b)
    abort();
  if (test3u(a) != b)
    abort();
  if (test4u(a) != b)
    abort();
  if (test5u(a) != b)
    abort();
  if (test6u(a) != b)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

#if INT_MAX == 2147483647
  test(atoi(argv[1]), atoi(argv[2]));
  testu(atoi(argv[3]), atoi(argv[4]));
#endif

#if INT_MAX == 32767
  test(atoi(argv[1]), atoi(argv[2]));
  testu(atoi(argv[3]), atoi(argv[4]));
#endif

  return 0;
}
