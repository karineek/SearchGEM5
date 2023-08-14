// Modification timestamp: 2023-08-14 15:53:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78856.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);

int a, b, c, d, e, f[3];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int g = 0, h, i = 0;
  for (; g < 21; g += 9) {
    int j = 1;
    for (h = 0; h < 3; h++)
      f[h] = atoi(argv[h + 1]);

    for (; j < 10; j++) {
      d = i && (b ? 0 : c);
      i = atoi(argv[4]);
      if (g)
        a = atoi(argv[5]);
    }
  }

  exit(0);
}
