// Modification timestamp: 2023-08-14 15:25:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr55750.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S
{
  int m : 1;
  int n : 7;
} arr[2];

__attribute__((noinline, noclone)) void foo(unsigned i)
{
  arr[i].n++;
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  arr[0].m = atoi(argv[1]);
  arr[0].n = atoi(argv[2]);
  arr[1].m = atoi(argv[3]);
  arr[1].n = atoi(argv[4]);

  foo(0);
  foo(1);

  if (arr[0].m != -1 || arr[0].n != -(1 << 6) || arr[1].m != 0 || arr[1].n != 0)
    abort();

  return 0;
}

In the converted code, the values of `arr[0].m`, `arr[0].n`, `arr[1].m`, and `arr[1].n` are taken as command line arguments.