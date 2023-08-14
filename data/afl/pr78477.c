// Modification timestamp: 2023-08-14 15:52:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78477.c

#include <stdio.h>

unsigned a;
unsigned short b;

unsigned foo(unsigned x) {
  b = x;
  a >>= (b & 1);
  b = 1 | (b << 5);
  b >>= 15;
  x = (unsigned char)b > ((2 - (unsigned char)b) & 1);
  b = 0;
  return x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (__CHAR_BIT__ != 8 || sizeof(short) != 2 || sizeof(int) < 4)
    return 0;

  unsigned x = foo(atoi(argv[1]));
  if (x != 0)
    __builtin_abort();
  return 0;
}

