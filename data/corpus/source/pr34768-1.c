// Modification timestamp: 2023-08-14 14:57:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34768-1.c

#include <stdio.h>
#include <stdlib.h>

int x;

void __attribute__((noinline)) foo (void)
{
  x = -x;
}

void __attribute__((const,noinline)) bar (void)
{
}

int __attribute__((noinline)) test (int c, int arg_x)
{
  int tmp = arg_x;
  (c ? foo : bar) ();
  return tmp + arg_x;
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  x = atoi(argv[1]);

  if (test(1, x) != 0)
    abort ();
  
  return 0;
}

