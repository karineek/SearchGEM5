// Modification timestamp: 2023-08-14 13:15:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20081112-1.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void foo(int a, int b)
{
  if (b != INT_MIN)
    abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = (a - 1) + INT_MIN;
  foo(a, b);

  return 0;
}
