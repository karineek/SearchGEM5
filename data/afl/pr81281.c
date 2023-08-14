// Modification timestamp: 2023-08-14 15:56:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81281.c

#include <stdio.h>
#include <stdlib.h>

void foo(unsigned p, unsigned a, unsigned b)
{
  unsigned q = p + 7;
  if (a - (1U + __INT_MAX__) >= 2)
    __builtin_unreachable ();
  int d = p + b;
  int c = p + a;
  if (c - d != __INT_MAX__)
    __builtin_abort ();
}

void bar(unsigned p, unsigned a)
{
  unsigned q = p + 7;
  if (a - (1U + __INT_MAX__) >= 2)
    __builtin_unreachable ();
  int c = p;
  int d = p + a;
  if (c - d != -__INT_MAX__ - 1)
    __builtin_abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned p = atoi(argv[1]);
  unsigned a = 1U + __INT_MAX__;
  unsigned b = 1U;
  foo(p, a, b);
  bar(p, a);
  return 0;
}
