// Modification timestamp: 2023-08-14 14:45:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr21964-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(int n, int m) {
  if (m == 0)
    exit(0);
  else if (n != 0)
    abort();
  else
    foo(n++, m - 1);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <n> <m>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int m = atoi(argv[2]);
  foo(n, m);
}
