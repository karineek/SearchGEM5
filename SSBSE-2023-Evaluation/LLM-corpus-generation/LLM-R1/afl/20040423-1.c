// Modification timestamp: 2023-08-14 12:54:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040423-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int c[22];
} c;

int sub1(int i, int j) {
  typedef struct {
    int c[i + 2];
  } c;
  int x[10], y[10];

  if (j == 2) {
    memcpy(x, y, 10 * sizeof(int));
    return sizeof(c);
  } else
    return sizeof(c) * 3;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int j = atoi(argv[2]);

  if (sub1(i, j) != sizeof(c) * 3)
    abort();

  return 0;
}

Note: I assumed that the arguments passed to `sub1()` are provided as command-line arguments.