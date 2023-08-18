// Modification timestamp: 2023-08-14 17:04:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-6.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void exit (int);
extern void abort ();

void test01(unsigned int a, unsigned int b)
{
  if (a < 5)
    abort();
  if (b < 5)
    abort();
  if (a - b != 5)
    abort();
}

void test02(unsigned int a, unsigned int b)
{
  if (a >= 12)
    if (b > 15)
      if (a - b < UINT_MAX - 15U)
        abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned x = atoi(argv[1]);
  test01(x + 5, x);
  test02(14, 16);
  exit (0);
}
