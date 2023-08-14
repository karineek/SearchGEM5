// Modification timestamp: 2023-08-14 15:54:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79286.c

#include <stdio.h>

int a = 0, c = 0;
static int d[][8] = {};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int e = atoi(argv[1]);
  for (int b = 0; b < 4; b++) {
    printf("%d\n", b, e);
    while (a && c++) {
      e = d[atoi(argv[2])][0];
    }
  }

  return 0;
}

