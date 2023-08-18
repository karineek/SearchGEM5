// Modification timestamp: 2023-08-14 15:27:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56899.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) void
f1(int v, int arg1)
{
  int x = -214748365 * (v - 1);
  if (x != arg1)
    __builtin_abort();
}

__attribute__((noinline, noclone)) void
f2(int v, int arg2)
{
  int x = 214748365 * (v + 1);
  if (x != arg2)
    __builtin_abort();
}

__attribute__((noinline, noclone)) void
f3(unsigned int v, unsigned int arg3)
{
  unsigned int x = -214748365U * (v - 1);
  if (x != arg3)
    __builtin_abort();
}

__attribute__((noinline, noclone)) void
f4(unsigned int v, unsigned int arg4)
{
  unsigned int x = 214748365U * (v + 1);
  if (x != arg4)
    __builtin_abort();
}

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4>\n", argv[0]);
    return 1;
  }

  f1(10, atoi(argv[1]));
  f2(-10, atoi(argv[2]));
  f3(10, atoi(argv[3]));
  f4(-10U, atoi(argv[4]));

  return 0;
}


//Note: The main function now accepts four command-line arguments.