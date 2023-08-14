// Modification timestamp: 2023-08-14 12:59:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041112-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef __SIZE_TYPE__ size_t;

int global;

static void *foo(int p)
{
  if (p == 0)
   {
      global++;
      return &global;
   }

  return (void *)(size_t)-1;
}

int bar(void)
{
  void *p;

  p = foo(global);
  if (p != (void *)(size_t)-1)
    return 1;

  global++;
  return 0;
}

int main(void)
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  global = argc;
  if (bar () != 0)
    abort();

  return 0;
}
