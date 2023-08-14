// Modification timestamp: 2023-08-14 17:01:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-9.c

#include <stdarg.h>
#include <stdlib.h>

extern __SIZE_TYPE__ strlen(const char *);

int to_hex(unsigned int a)
{
  static char hex[] = "0123456789abcdef";

  if (a > 15)
    abort ();
  return hex[a];
}

void format_and_print(int index, char *format, ...)
{
  va_list ap;
  va_start(ap, format);

  if (strlen(format) != 16 - index)
    abort();

  while (*format)
  {
    if (*format++ != to_hex(va_arg(ap, int)))
      abort();
  }

  va_end(ap);
}

int main(int argc, char *argv[])
{
  char *f = "0123456789abcdef";

  format_and_print(0, f + 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(1, f + 1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(2, f + 2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(3, f + 3, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(4, f + 4, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(5, f + 5, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(6, f + 6, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(7, f + 7, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(8, f + 8, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(9, f + 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(10, f + 10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(11, f + 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(12, f + 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(13, f + 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(14, f + 14, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  format_and_print(15, f + 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

  return 0;
}
