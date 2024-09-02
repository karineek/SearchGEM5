// Modification timestamp: 2023-08-14 15:42:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64979.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void __attribute__((noinline, noclone))
bar (int x, va_list *ap)
{
  if (ap)
  {
    int i;
    for (i = 0; i < 10; i++)
      if (i != va_arg(*ap, int))
        __builtin_abort();
    if (va_arg(*ap, double) != 0.5)
      __builtin_abort();
  }
}

void __attribute__((noinline, noclone))
foo (int x, ...)
{
  va_list ap;
  int n;

  va_start(ap, x);
  n = va_arg(ap, int);
  bar(x, (va_list *)((n == 0) ? ((void *)0) : &ap));
  va_end(ap);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  foo(x, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0.5);
  return 0;
}
