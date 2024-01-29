// Modification timestamp: 2023-08-14 15:30:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58364.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c;

int foo(int x)
{
  return x < 0 ? 1 : x;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);

  if (foo(a > c == (b = 0)))
    __builtin_abort();
  return 0;
}
