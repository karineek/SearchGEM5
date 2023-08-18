// Modification timestamp: 2023-08-14 14:54:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr32244-1.c

#include <stdio.h>
#include <stdlib.h>

struct foo
{
  unsigned long long b:40;
} x;

extern void abort (void);

void test1(unsigned long long res)
{
  /* The shift is carried out in 40 bit precision.  */
  if (x.b<<32 != res)
    abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x.b = atoi(argv[1]);
  test1(0);
  return 0;
}
