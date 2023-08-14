// Modification timestamp: 2023-08-14 15:41:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64957.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int foo(int b) {
  return (((b ^ 5) | 1) ^ 5) | 1;
}

__attribute__((noinline, noclone)) int bar(int b) {
  return (((b ^ ~5) & ~1) ^ ~5) & ~1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  for (i = 0; i < 16; i++)
    if (foo(i) != (i | 1) || bar(i) != (i & ~1))
      __builtin_abort();

  return 0;
}
