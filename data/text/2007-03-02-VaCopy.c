
// Modification timestamp: 2023-08-10 15:26:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2007-03-02-VaCopy.c

#include <stdio.h>
#include <stdarg.h>

void testVaCopyArg(char *fmt, ...) {
  va_list ap, aq;
  char *s;
  va_start(ap, fmt);
  va_copy(aq, ap);    /* test va_copy */

  s = va_arg(aq, char *);
  printf("string %s\n", s);
}

int main() {
  testVaCopyArg("s", "abc");
  return 0;
}
