// Modification timestamp: 2023-08-14 13:44:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960302-1.c

#include <stdio.h>
#include <stdlib.h>

long a = 1;

int foo() {
  switch (a % 2 % 2 % 2 % 2 % 2 % 2 % 2 % 2) {
    case 0:
      return 0;
    case 1:
      return 1;
    default:
      return -1;
  }
}

int main() {
  if (foo() != 1)
    abort();
  exit(0);
}
