// Modification timestamp: 2023-08-14 13:39:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931102-2.c

#include <stdio.h>
#include <stdlib.h>

typedef union
{
  long align;
  struct
  {
    short h, l;
  } b;
} T;

int f(int x)
{
  int num = 0;
  T reg;

  reg.b.l = x;
  while ((reg.b.l & 1) == 0)
  {
    num++;
    reg.b.l >>= 1;
  }
  return num;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = f(atoi(argv[1]));
  if (result != 1)
    abort();

  exit(0);
}
