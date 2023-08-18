// Modification timestamp: 2023-08-14 13:25:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920428-1.c

#include <stdio.h>
#include <stdlib.h>

int x(const char *s) {
  char a[1];
  const char *ss = s;
  a[*s++] |= 1;
  return (int)ss+1 == (int)s;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (x("") != 1) {
    abort();
  }
  exit(0);
}
