// Modification timestamp: 2023-08-14 13:03:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050410-1.c

#include <stdio.h>
#include <stdlib.h>

int s = 200;

int __attribute__((noinline)) foo(void) {
  return (signed char) (s - 100) - 5;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int s = atoi(argv[1]);

  if (foo() != 95) {
    abort();
  }

  exit(0);
}
