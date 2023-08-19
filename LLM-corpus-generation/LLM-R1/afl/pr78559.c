// Modification timestamp: 2023-08-14 15:52:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78559.c

#include <stdio.h>
#include <stdlib.h>

int g = 20;
int d = 0;

short fn2(int p1, int p2) {
  return p2 >= 2 || 5 >> p2 ? p1 : p1 << p2;
}

int main() {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = 0;
lbl_2582:
  if (g) {
    for (int c = -3; c; c++) {
      result = fn2(1, g);
    }
  } else {
    for (int i = 0; i < 2; i += 2) {
      if (d) {
        goto lbl_2582;
      }
    }
  }
  if (result != atoi(argv[1])) {
    __builtin_abort();
  }
  return 0;
}
