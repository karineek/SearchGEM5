// Modification timestamp: 2023-08-14 15:46:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68321.c

#include <stdio.h>
#include <stdlib.h>

int e = 1, u = 5, t2, t5, i, k;
int a[1], b, m;
char n, t;

int fn1(char p1)
{
  int g[1];
  for (;;)
  {
    if (p1 / 3)
      for (; t5;)
        u || n;
    t2 = p1 & 4;
    if (b + 1)
      return 0;
    u = g[0];
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  for (; e >= 0; e--)
  {
    char c = argv[1][0];
    if (!m)
      c = t;
    fn1(c);
  }

  if (a[t2] != 0)
    __builtin_abort();

  return 0;
}
