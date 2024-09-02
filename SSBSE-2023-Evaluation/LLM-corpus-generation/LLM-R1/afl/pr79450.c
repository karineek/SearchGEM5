// Modification timestamp: 2023-08-14 15:54:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79450.c

#include <stdio.h>
#include <stdlib.h>

unsigned int foo(unsigned char x, unsigned long long y) {
  do {
    x &= !y;
    x %= 24;
  } while (x < y);
  return x + y;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  unsigned char x = atoi(argv[1]);
  unsigned long long y = atoll(argv[2]);
  
  unsigned int result = foo(x, y);
  if (result != 1) {
    __builtin_abort();
  }
  
  return 0;
}
