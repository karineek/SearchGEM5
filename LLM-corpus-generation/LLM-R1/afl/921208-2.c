// Modification timestamp: 2023-08-14 13:32:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921208-2.c

#include <stdio.h>
#include <stdlib.h>

void g(float arg1, float arg2) {
  // Function implementation
}

void f() {
  int i;
  float a[100000];

  for (i = 0; i < 1; i++) {
    g(1.0, 1.0 + i / 2.0 * 3.0);
    g(2.0, 1.0 + i / 2.0 * 3.0);
  }
}

int main(int argc, char *argv[]) {
  f();
  exit(0);
}
