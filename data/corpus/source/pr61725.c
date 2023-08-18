// Modification timestamp: 2023-08-14 15:39:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61725.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  for (x = -128; x <= 128; x++) {
    int a = __builtin_ffs(x);
    if (x == 0 && a != 0)
      __builtin_abort();
  }

  return 0;
}
