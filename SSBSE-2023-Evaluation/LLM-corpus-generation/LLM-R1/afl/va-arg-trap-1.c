// Modification timestamp: 2023-08-14 17:02:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-trap-1.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);

va_list ap;
float f;

va_list *foo(int argc, ...)
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  va_start(ap, argc);
  f = va_arg(ap, float);
  va_end(ap);

  return &ap;
}

void bar(int i, ...)
{
  va_start(ap, i);
  f = va_arg(*foo(i, 0), float);
  va_end(ap);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    exit(1);
  }

  bar(1, 0);
  abort();
}

