// Modification timestamp: 2023-08-14 13:09:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070614-1.c
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

_Complex v;

void foo(_Complex z, int *x)
{
  if (z != v)
    abort();
}

_Complex bar(_Complex z);

_Complex bar(_Complex z)
{
  return v;
}

int baz(void)
{
  int a, i;
  for (i = 0; i < 6; i++)
    foo(bar(1.0iF * i), &a);
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  v = atof(argv[1]) + atof(argv[2]) * 1;
  baz();
  return 0;
}
