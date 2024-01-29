// Modification timestamp: 2023-08-14 13:33:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930526-1.c
#include <string.h>

#include <stdlib.h>

void f(int x) {
  int *(p[25]);
  int m[25 * 7];
  int i;

  for (i = 0; i < 25; i++)
    p[i] = m + x * i;

  p[1][0] = 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  f(x);
  exit(0);
}

//Note: I added the missing `#include <stdio.h>` directive at the beginning of the code.