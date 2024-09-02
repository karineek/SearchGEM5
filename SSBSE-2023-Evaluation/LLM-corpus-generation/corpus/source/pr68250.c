// Modification timestamp: 2023-08-14 15:46:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68250.c

#include <stdio.h>
#include <stdlib.h>

signed char a, b, h, k, l, m, o;
short c, d, n;
int e, f, g, j, q;

void fn1(void)
{
  int p = b || a;
  n = o > 0 || d > 1 >> o ? d : d << o;
  for (; j; j++)
    m = c < 0 || m || c << p;
  l = f + 1;
  for (; f < 1; f = 1)
    k = h + 1;
}

__attribute__((noinline, noclone)) void fn2(int k)
{
  if (k != 1)
    __builtin_abort();
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char i;
  int k = atoi(argv[1]);
  for (; e < 1; e++)
  {
    fn1();
    if (k)
      i = k;
    if (i > q)
      g = 0;
  }
  fn2(k);
  return 0;
}
