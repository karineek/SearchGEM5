// Modification timestamp: 2023-08-14 15:23:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53465.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

void foo(const int *x, int y)
{
  int i;
  int b = 0;
  int c;
  for (i = 0; i < y; i++)
  {
    int d = x[i];
    if (d == 0)
      break;
    if (b && d <= c)
      abort();
    c = d;
    b = 1;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int y = atoi(argv[1]);
  foo(argv + 2, y);
  return 0;
}
