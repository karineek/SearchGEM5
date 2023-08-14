
// Modification timestamp: 2023-08-10 14:47:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2003-05-14-AtExit.c

#include <stdlib.h>
#include <stdio.h>

static void foo() {
  printf("Exiting!\n");
}

int main() {
  atexit(foo);
  printf("in main\n");
  return 0;
}
