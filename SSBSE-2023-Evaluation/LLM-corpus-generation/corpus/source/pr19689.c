// Modification timestamp: 2023-08-14 14:44:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19689.c
#include <stdlib.h>
#include <stdio.h>

struct
{
  int b : 29;
} f;

void foo(short j)
{
  f.b = j;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short j = atoi(argv[1]);
  foo(j);
  if (f.b != j)
    abort();
  return 0;
}