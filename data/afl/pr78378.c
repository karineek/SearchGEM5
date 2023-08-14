// Modification timestamp: 2023-08-14 15:52:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78378.c

#include <stdio.h>
#include <stdlib.h>

unsigned long long foo(unsigned long long x) {
  x <<= 41;
  x /= 232;
  return 1 + (unsigned short) x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long long x = foo(atoll(argv[1]));
  if (x != 0x2c24)
    __builtin_abort();
  return 0;
}
