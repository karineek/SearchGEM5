// Modification timestamp: 2023-08-14 15:50:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71335.c

#include <stdio.h>
#include <stdlib.h>

int a;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[2]);

  while (a < atoi(argv[1]) || b) {
    b = 0;
    for (; b < 9; b++)
      ;
  }

  exit(0);
}
