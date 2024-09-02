// Modification timestamp: 2023-08-14 12:52:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040311-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

#define INT_BITS  (sizeof(int)*8)

int test1(int x)
{
  return -(x >> (INT_BITS-1));
}

int test2(unsigned int x)
{
  return -((int)(x >> (INT_BITS-1)));
}

int test3(int x)
{
  int y;
  y = INT_BITS-1;
  return -(x >> y);
}

int test4(unsigned int x)
{
  int y;
  y = INT_BITS-1;
  return -((int)(x >> y));
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  if (test1(0) != 0)
    abort ();
  if (test1(1) != 0)
    abort ();
  if (test1(-1) != 1)
    abort ();

  if (test2(0) != 0)
    abort ();
  if (test2(1) != 0)
    abort ();
  if (test2((unsigned int)-1) != -1)
    abort ();

  if (test3(0) != 0)
    abort ();
  if (test3(1) != 0)
    abort ();
  if (test3(-1) != 1)
    abort ();

  if (test4(0) != 0)
    abort ();
  if (test4(1) != 0)
    abort ();
  if (test4((unsigned int)-1) != -1)
    abort ();

  return 0;
}
