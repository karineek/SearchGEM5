// Modification timestamp: 2023-08-14 13:30:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921007-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int my_strcmp() {
  return -1;
}

#define strcmp __builtin_strcmp

int main(int argc, char *argv[]) {
  if (strcmp("X", "X\376") >= 0) {
    abort();
  }
  exit(0);
}
