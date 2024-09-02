// Modification timestamp: 2023-08-14 15:25:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr55137.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort(void);

int foo(unsigned int x)
{
  return ((int)(x + 1U) + 1) < (int)x;
}

int bar(unsigned int x)
{
  return (int)(x + 1U) + 1;
}

int baz(unsigned int x)
{
  return x + 1U;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x = (unsigned int)atoi(argv[1]);

  if (foo(UINT_MAX) != (bar(UINT_MAX) < UINT_MAX) || foo(UINT_MAX) != ((int)baz(UINT_MAX) + 1 < UINT_MAX))
    abort();

  return 0;
}
