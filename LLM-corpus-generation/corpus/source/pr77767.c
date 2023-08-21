// Modification timestamp: 2023-08-14 15:52:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr77767.c
#include <stdio.h>
#include <stdlib.h>

void foo(int a, int b[a++], int c, int d[c++])
{
  if (a != 2 || c != 2)
    __builtin_abort();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int e[10];
  
  int a = atoi(argv[1]);
  int c = atoi(argv[2]);
  
  foo(a, e, c, e);
  return 0;
}
