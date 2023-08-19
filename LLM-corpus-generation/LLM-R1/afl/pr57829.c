// Modification timestamp: 2023-08-14 15:28:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57829.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone))
int f1(int k)
{
  return 2 | ((k - 1) >> ((int) sizeof(int) * __CHAR_BIT__ - 1));
}

__attribute__((noinline, noclone))
long int f2(long int k)
{
  return 2L | ((k - 1L) >> ((int) sizeof(long int) * __CHAR_BIT__ - 1));
}

__attribute__((noinline, noclone))
int f3(int k)
{
  k &= 63;
  return 4 | ((k + 2) >> 5);
}

int main(int argc, char *argv[])
{
  if (f1(atoi(argv[1])) != 2 || f2(atol(argv[2])) != 2L || f3(atoi(argv[3])) != 6 || f3(atoi(argv[4])) != 4)
    __builtin_abort();
  return 0;
}
