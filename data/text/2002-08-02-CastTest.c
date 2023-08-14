
// Modification timestamp: 2023-08-10 14:43:46
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>

unsigned test(unsigned X) {
  return (unsigned char)X;
}

int main() {
    printf("%d\n", test(123456));
    return 0;
}
