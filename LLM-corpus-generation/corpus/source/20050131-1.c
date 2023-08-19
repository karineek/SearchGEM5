// Modification timestamp: 2023-08-14 13:02:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050131-1.c

#include <stdlib.h>
#include <stdio.h>

int foo(int a) {
  int x = 0 % a++;
  return a;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);
  if (foo(arg) != arg + 1) {
    abort();
  }
  exit(0);
}
