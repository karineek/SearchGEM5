// Modification timestamp: 2023-08-14 13:28:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920618-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (1.17549435e-38F <= 1.1) {
    exit(0);
  }
  abort();
}
