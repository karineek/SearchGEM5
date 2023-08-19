// Modification timestamp: 2023-08-14 13:25:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920409-1.c

#include <stdio.h>
#include <stdlib.h>

int x() {
  signed char c = -1;
  return c < 0;
}

int main(int argc, char *argv[]) {
  if (x() != 1)
    abort();
  exit(0);
}
