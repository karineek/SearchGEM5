// Modification timestamp: 2023-08-14 13:34:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930622-1.c

#include <stdio.h>
#include <stdlib.h>

int a = 1, b;

int g() { return 0; }

void h(int x) {}

int f() {
  if (g() == -1)
    return 0;
  a = g();
  if (b >= 1)
    h(a);
  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f();
  if (a != 0)
    abort();
  exit(0);
}
