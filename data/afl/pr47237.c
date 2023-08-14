// Modification timestamp: 2023-08-14 15:15:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47237.c

#include <stdio.h>
#include <stdlib.h>

#define INTEGER_ARG 5

extern void abort(void);

static void foo(int arg)
{
  if (arg != atoi(argv[1]))
    abort();
}

static void bar(int arg)
{
  foo(arg);
  __builtin_apply(foo, __builtin_apply_args(), 16);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  bar(atoi(argv[1]));

  return 0;
}
