// Modification timestamp: 2023-08-14 17:12:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-14-AtExit.c

#include <stdlib.h>
#include <stdio.h>

static void foo() {
  printf("Exiting!\n");
}

int main(int argc, char *argv[]) {
  atexit(foo);
  printf("in main\n");
  return 0;
}
