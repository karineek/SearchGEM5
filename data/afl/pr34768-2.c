// Modification timestamp: 2023-08-14 14:57:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34768-2.c

#include <stdio.h>
#include <stdlib.h>

int x;

int __attribute__((noinline)) foo (void)
{
  x = -x;
  return 0;
}

int __attribute__((const,noinline)) bar (void)
{
  return 0;
}

int __attribute__((noinline)) test (int c)
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int tmp = atoi(argv[1]);
  int res = (c ? foo : bar) ();
  return tmp + x + res;
}

extern void abort (void);

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);
  
  if (test (1) != 0)
    abort ();
  
  return 0;
}
