// Modification timestamp: 2023-08-14 13:23:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20180131-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef union
{
  signed short ss;
  unsigned short us;
  int x;
} U;

int f(int x, int y, int z, int a, U u) __attribute__((noclone, noinline));

int f(int x, int y, int z, int a, U u)
{
  return (u.ss <= 0) + u.us;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  U u = {.ss = atoi(argv[1])};

  if (f(0, 0, 0, 0, u) != (1 << sizeof(short) * 8))
    abort();

  return 0;
}
