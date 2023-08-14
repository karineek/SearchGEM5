
// Modification timestamp: 2023-08-10 14:43:46
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>

unsigned test(unsigned X) {
  return (unsigned char)X;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned X = atoi(argv[1]);
  printf("%d\n", test(X));
  return 0;
}
