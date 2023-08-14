// Modification timestamp: 2023-08-14 12:42:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030209-1.c

#include <stdio.h>
#include <stdlib.h>

double x[100][100];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  x[i][0] = 42;

  if (x[atoi(argv[2])][0] != atoi(argv[3])) {
    abort();
  }

  exit(0);
}
