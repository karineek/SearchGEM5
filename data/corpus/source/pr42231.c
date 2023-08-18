// Modification timestamp: 2023-08-14 15:08:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42231.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static int max;

static void __attribute__((noinline)) storemax(int i)
{
  if (i > max)
    max = i;
}

static int CallFunctionRec(int (*fun)(int depth), int depth)
{
  if (!fun(depth))
  {
    return 0;
  }
  if (depth < 10)
  {
    CallFunctionRec(fun, depth + 1);
  }
  return 1;
}

static int CallFunction(int (*fun)(int depth))
{
  return CallFunctionRec(fun, 1) && !fun(0);
}

static int callback(int depth)
{
  storemax(depth);
  return depth != 0;
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  CallFunction(callback);
  if (max != 10)
    abort();
  return 0;
}
