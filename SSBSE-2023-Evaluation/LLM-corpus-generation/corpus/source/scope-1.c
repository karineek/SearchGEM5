// Modification timestamp: 2023-08-14 16:09:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/scope-1.c

#include <stdio.h>
#include <stdlib.h>

int v = 3;

void f() {
  int v = 4;
  {
    extern int v;
    if (v != 3)
      abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f();
  exit(0);
}
