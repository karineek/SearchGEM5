// Modification timestamp: 2023-08-14 13:33:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930513-1.c

#include <stdio.h>
#include <stdlib.h>

char buf[2];

void f(int (*fp)(char *, const char *, ...)) {
  (*fp)(buf, "%.0f", 5.0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f(&sprintf);
  if (buf[0] != '5' || buf[1] != 0)
    abort();
  exit(0);
}
