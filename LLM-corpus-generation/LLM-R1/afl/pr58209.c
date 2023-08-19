// Modification timestamp: 2023-08-14 15:29:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58209.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
typedef __INTPTR_TYPE__ T;
T buf[1024];

T *foo(T n, T *argv[])
{
  if (n == 0)
    return (T *)buf;

  T *s = (T *)foo(n - 1, argv);
  return (T *)(s + sizeof(T));
}

T *bar(T n, T *argv[])
{
  if (n == 0)
    return buf;

  return foo(n - 1, argv) + sizeof(T);
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < 27; i++)
  {
    if (foo(i, argv) != buf + i || bar(i, argv) != buf + i)
      abort();
  }

  return 0;
}
