// Modification timestamp: 2023-08-14 14:28:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/inst-check.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int f(int m) {
  int i, s = 0;
  for (i = 0; i < m; i++)
    s += i;
  return s;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int m = atoi(argv[1]);
  int result = f(m);
  exit(result);
}
