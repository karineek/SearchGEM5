// Modification timestamp: 2023-08-14 13:08:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20061220-1.c
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(unsigned int x)
{
  void nested(unsigned int *x)
  {
    *x = 254;
  }

  nested(&x);
  asm volatile("" :: "r" (x));
  asm volatile("" :: "m" (x));
  asm volatile("" :: "mr" (x));
  asm volatile("" : "=r" (x) : "0" (x));
  asm volatile("" : "=m" (x) : "m" (x));
  return x;
}

int bar(unsigned int x)
{
  void nested(unsigned int *x)
  {
    asm volatile("" :: "r" (*x));
    asm volatile("" :: "m" (*x));
    asm volatile("" :: "mr" (*x));
    *x += 4;
    asm volatile("" : "=r" (*x) : "0" (*x));
    asm volatile("" : "=m" (*x) : "m" (*x));
  }

  nested(&x);
  return x;
}

int baz(unsigned int x)
{
  void nested2(unsigned int *x)
  {
    asm volatile("" :: "r" (*x));
    asm volatile("" :: "m" (*x));
    asm volatile("" :: "mr" (*x));
    *x += 4;
    asm volatile("" : "=r" (*x) : "0" (*x));
    asm volatile("" : "=m" (*x) : "m" (*x));
  }

  void nested(unsigned int *x)
  {
    nested2(x);
    nested2(x);
  }

  nested(&x);
  return x;
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  unsigned int x1 = atoi(argv[1]);
  unsigned int x2 = atoi(argv[2]);
  unsigned int x3 = atoi(argv[3]);

  if (foo(x1) != 254 || bar(x2) != 4 || baz(x3) != 8)
    abort();
  return 0;
}
