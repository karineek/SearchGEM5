// Modification timestamp: 2023-08-14 13:29:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920726-1.c

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

struct spurious
{
    int anumber;
};

int first(char *buf, char *fmt, ...)
{
  int pos, number;
  va_list args;
  int dummy;
  char *bp = buf;

  va_start(args, fmt);
  for (pos = 0; fmt[pos]; pos++)
    if (fmt[pos] == 'i')
      {
	number = va_arg(args, int);
	sprintf(bp, "%d", number);
	bp += strlen(bp);
      }
    else
      *bp++ = fmt[pos];

  va_end(args);
  *bp = 0;
  return dummy;
}

struct spurious second(char *buf,char *fmt, ...)
{
  int pos, number;
  va_list args;
  struct spurious dummy;
  char *bp = buf;

  va_start(args, fmt);
  for (pos = 0; fmt[pos]; pos++)
    if (fmt[pos] == 'i')
      {
	number = va_arg(args, int);
	sprintf(bp, "%d", number);
	bp += strlen(bp);
      }
    else
      *bp++ = fmt[pos];

  va_end(args);
  *bp = 0;
  return dummy;
}

int main() {
  char buf1[100], buf2[100];
  int a = 5;
  int b = 20;

  first(buf1, "i i ", a, b);
  second(buf2, "i i ", a, b);
  if (strcmp ("5 20 ", buf1) || strcmp ("5 20 ", buf2))
    abort();
  exit(0);
}
