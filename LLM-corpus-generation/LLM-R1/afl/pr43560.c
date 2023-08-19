// Modification timestamp: 2023-08-14 15:11:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43560.c

#include <stdio.h>

struct S
{
  int a, b;
  char c[10];
};

__attribute__ ((noinline)) void
test(struct S *x)
{
  while (x->b > 1 && x->c[x->b - 1] == '/')
  {
    x->b--;
    x->c[x->b] = '\0';
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S s = { atoi(argv[1]), 0, "" };
  struct S *p;
  asm ("" : "=r" (p) : "0" (&s));
  test(p);
  return 0;
}
