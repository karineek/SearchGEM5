
// Modification timestamp: 2023-08-10 15:27:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/Programs/single-source/2007-04-25-weak.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int (*t)() = test_weak;
  if (t) {
    t();
    return 1;
  }
  return 0;
}
