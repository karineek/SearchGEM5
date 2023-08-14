// Modification timestamp: 2023-08-14 17:18:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2006-01-29-SimpleIndirectCall.c

#include <stdio.h>

void hello() {
  printf("Hello, world!\n");
}

void goodbye() {
  printf("Goodbye, world!\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  void (*f)() = (atoi(argv[1]) > 1) ? &hello : &goodbye;
  f();
  return 0;
}
