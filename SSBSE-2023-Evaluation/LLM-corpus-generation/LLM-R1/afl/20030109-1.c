// Modification timestamp: 2023-08-14 12:41:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030109-1.c

#include <stdio.h>
#include <stdlib.h>

struct X
{
  int a;
  int b;
  int z[];
};

struct X x = { .b = 40, .z = {} };

int main()
{
  if (x.b != 40)
    abort();

  return 0;
}
