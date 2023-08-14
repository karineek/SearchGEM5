// Modification timestamp: 2023-08-14 12:36:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020916-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(int a) {
  int x;
  x = 0;
  if (a > 0) x = 1;
  if (a < 0) x = 1;
  return x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <a>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);

  if (foo(a) != 1)
    abort();

  return 0;
}
