// Modification timestamp: 2023-08-14 16:53:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ret-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned char a;
  unsigned short b;
} three_byte_t;

unsigned char f(void) {
  return 0xab;
}

unsigned short g(void) {
  return 0x1234;
}

int main(int argc, char *argv[]) {
  three_byte_t three_byte;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  three_byte.a = f();
  three_byte.b = g();
  if (three_byte.a != 0xab || three_byte.b != 0x1234)
    abort();
  exit(0);
}
