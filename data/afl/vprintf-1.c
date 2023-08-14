// Modification timestamp: 2023-08-14 17:03:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vprintf-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void inner(int x, ...) {
  va_list ap, ap2;
  va_start(ap, x);
  va_start(ap2, x);

  switch (x) {
    case 0:
      vprintf("hello", ap);
      if (vprintf("hello", ap2) != 5)
        abort();
      break;
    case 1:
      vprintf("hello\n", ap);
      if (vprintf("hello\n", ap2) != 6)
        abort();
      break;
    case 2:
      vprintf("a", ap);
      if (vprintf("a", ap2) != 1)
        abort();
      break;
    case 3:
      vprintf("", ap);
      if (vprintf("", ap2) != 0)
        abort();
      break;
    case 4:
      vprintf("%s", ap);
      if (vprintf("%s", ap2, "hello") != 5)
        abort();
      break;
    case 5:
      vprintf("%s", ap);
      if (vprintf("%s", ap2, "hello\n") != 6)
        abort();
      break;
    case 6:
      vprintf("%s", ap);
      if (vprintf("%s", ap2, "a") != 1)
        abort();
      break;
    case 7:
      vprintf("%s", ap);
      if (vprintf("%s", ap2, "") != 0)
        abort();
      break;
    case 8:
      vprintf("%c", ap);
      if (vprintf("%c", ap2, 'x') != 1)
        abort();
      break;
    case 9:
      vprintf("%s\n", ap);
      if (vprintf("%s\n", ap2, "hello\n") != 7)
        abort();
      break;
    case 10:
      vprintf("%d\n", ap);
      if (vprintf("%d\n", ap2, 0) != 2)
        abort();
      break;
    default:
      abort();
  }

  va_end(ap);
  va_end(ap2);
}

int main(void) {
  inner(0);
  inner(1);
  inner(2);
  inner(3);
  inner(4, "hello");
  inner(5, "hello\n");
  inner(6, "a");
  inner(7, "");
  inner(8, 'x');
  inner(9, "hello\n");
  inner(10, 0);

  return 0;
}
