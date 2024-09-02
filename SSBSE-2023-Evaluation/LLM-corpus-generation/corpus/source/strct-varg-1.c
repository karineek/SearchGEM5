// Modification timestamp: 2023-08-14 16:15:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-varg-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct s { int x, y; };

void f(int attr, ...)
{
  va_list va;
  va_start(va, attr);

  if (attr != 2)
    abort();

  struct s va_values = va_arg(va, struct s);
  if (va_values.x != 0xaaaa || va_values.y != 0x5555)
    abort();

  attr = va_arg(va, int);
  if (attr != 3)
    abort();

  va_values = va_arg(va, struct s);
  if (va_values.x != 0xffff || va_values.y != 0x1111)
    abort();

  va_end(va);
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  struct s a, b;

  a.x = 0xaaaa;
  a.y = 0x5555;
  b.x = 0xffff;
  b.y = 0x1111;

  f(atoi(argv[1]), a, 3, b);
  exit(0);
}
