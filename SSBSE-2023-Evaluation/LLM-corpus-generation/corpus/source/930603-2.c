// Modification timestamp: 2023-08-14 13:34:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930603-2.c

#include <stdio.h>
#include <stdlib.h>

int w[2][2];

void f() {
  int i, j;

  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
      if (i == j)
        w[i][j] = 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  f();
  
  if (w[0][0] != atoi(argv[1]) || w[1][1] != atoi(argv[2]) || w[1][0] != atoi(argv[3]) || w[0][1] != atoi(argv[4])) {
    abort();
  }
  
  exit(0);
}
