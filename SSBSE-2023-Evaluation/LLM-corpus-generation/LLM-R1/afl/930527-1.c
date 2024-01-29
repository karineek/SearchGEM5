// Modification timestamp: 2023-08-14 13:33:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930527-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned char f(unsigned char x) {
  return (0x50 | (x >> 4)) ^ 0xff;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  if (f(0) != 0xaf) {
    abort();
  }
  
  exit(0);
}
