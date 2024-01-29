// Modification timestamp: 2023-08-14 17:23:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2007-03-02-VaCopy.c
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
