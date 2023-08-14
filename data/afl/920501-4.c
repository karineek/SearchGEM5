// Modification timestamp: 2023-08-14 13:26:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-4.c

#include <stdio.h>
#include <stdlib.h>

int x(int i);

int main() {
  if (x(0) != 2 || x(1) != 3 || x(2) != 5) {
    abort();
  }

  exit(0);
}

int x(int i) {
  static const void *j[] = {&&x, &&y, &&z};

  goto *j[i];

x:
  return 2;
y:
  return 3;
z:
  return 5;
}
