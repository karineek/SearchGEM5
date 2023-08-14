// Modification timestamp: 2023-08-14 13:17:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090219-1.c

#include <stdio.h>
#include <stdlib.h>

void bar(int a, int b, int c, int d, int e) {
  if (e != 0) {
    abort();
  }
}

void foo(void) {
  int f = 0;

  bar(0, 0, 0, 0, 0);
}

int main(int argc, char *argv[]) {
  foo();
  exit(0);
}
