// Modification timestamp: 2023-08-14 12:54:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040411-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sub1(int i, int j) {
  typedef int c[i + 2];
  int x[10], y[10];

  if (j == 2) {
    memcpy(x, y, 10 * sizeof(int));
    return sizeof(c);
  } else
    return sizeof(c) * 3;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int result = sub1(atoi(argv[1]), atoi(argv[2]));
  if (result != 66 * sizeof(int))
    abort();

  return 0;
}
