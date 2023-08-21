// Modification timestamp: 2023-08-14 14:53:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31072.c
#include <stdio.h>
#include <stdlib.h>

extern volatile int ReadyFlag_NotProperlyInitialized;

volatile int ReadyFlag_NotProperlyInitialized = 1;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (ReadyFlag_NotProperlyInitialized != atoi(argv[1])) {
    abort();
  }

  return 0;
}
