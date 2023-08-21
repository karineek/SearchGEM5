// Modification timestamp: 2023-08-14 15:40:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr63843.c
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

static inline __attribute__ ((always_inline))
unsigned short foo(unsigned short v) {
  return (v << 8) | (v >> 8);
}

unsigned short __attribute__ ((noinline, noclone, hot))
bar(unsigned char *x, int a, unsigned short b) {
  a ^= 0x80808080U;
  memcpy(&x[0], &a, sizeof(a));
  memcpy(&b, &x[2], sizeof(b));
  return foo(b);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char x[8] = { 0x01, 0x01, 0x01, 0x01 };
  int a = atoi(argv[1]);
  unsigned short b;

  if (__CHAR_BIT__ == 8
      && sizeof(short) == 2
      && sizeof(int) == 4
      && bar(x, a, b) != 0x8181U) {
    abort();
  }

  return 0;
}
