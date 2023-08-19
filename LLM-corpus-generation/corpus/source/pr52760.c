// Modification timestamp: 2023-08-14 15:22:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52760.c

#include <stdio.h>
#include <stdlib.h>

struct T { unsigned short a, b, c, d; };

__attribute__((noinline, noclone)) void foo(int x, struct T *y) {
  int i;
  for (i = 0; i < x; i++) {
    y[i].a = ((0x00ff & y[i].a >> 8) | (0xff00 & y[i].a << 8));
    y[i].b = ((0x00ff & y[i].b >> 8) | (0xff00 & y[i].b << 8));
    y[i].c = ((0x00ff & y[i].c >> 8) | (0xff00 & y[i].c << 8));
    y[i].d = ((0x00ff & y[i].d >> 8) | (0xff00 & y[i].d << 8));
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct T t = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) };
  foo(1, &t);
  if (t.a != (0x00ff & atoi(argv[1]) >> 8) | (0xff00 & atoi(argv[1]) << 8) ||
      t.b != (0x00ff & atoi(argv[2]) >> 8) | (0xff00 & atoi(argv[2]) << 8) ||
      t.c != (0x00ff & atoi(argv[3]) >> 8) | (0xff00 & atoi(argv[3]) << 8) ||
      t.d != (0x00ff & atoi(argv[4]) >> 8) | (0xff00 & atoi(argv[4]) << 8)) {
    __builtin_abort();
  }
  return 0;
}
