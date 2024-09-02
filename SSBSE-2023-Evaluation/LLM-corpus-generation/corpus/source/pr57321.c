// Modification timestamp: 2023-08-14 15:28:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57321.c
#include <stdlib.h>

#include <stdio.h>

int a = 1;
int *b;
int **c;

static int foo(int *p) {
  if (*p == a) {
    int *i[7][5] = {{0}};
    int **j[1][1];
    j[0][0] = &i[0][0];
    *b = &p != c;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  foo(&i);
  return 0;
}
