// Modification timestamp: 2023-08-14 12:52:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040409-1w.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort();

int test2(int x)
{
  return x + INT_MIN;
}

int test3(int x)
{
  return x - INT_MIN;
}

int test5(int x)
{
  int y = INT_MIN;
  return x + y;
}

int test6(int x)
{
  int y = INT_MIN;
  return x - y;
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
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }
  
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  
  test(a, b);
#endif

#if INT_MAX == 32767
  test(0x0000,0x8000);
  test(0x8000,0x0000);
  test(0x1234,0x9234);
  test(0x9234,0x1234);
  test(0x7fff,0xffff);
  test(0xffff,0x7fff);
#endif

  return 0;
}
