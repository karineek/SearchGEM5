// Modification timestamp: 2023-08-14 11:57:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010221-1.c

#include <stdio.h>
#include <stdlib.h>

int n = 2;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i, x = atoi(argv[1]);

  for (i = 0; i < n; i++) {
    if (i != 0)
      x = (i > 0) ? i : 0;
  }

  if (x != 1)
    abort();

  exit(0);
}
