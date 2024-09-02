// Modification timestamp: 2023-08-14 13:40:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/940115-1.c

#include <stdio.h>
#include <stdlib.h>

int f(char *cp, char *end) {
  return (cp < end);
}

int main(int argc, char *argv[]) {
  if (!f(argv[1], argv[2]))
    abort();
  exit(0);
}
