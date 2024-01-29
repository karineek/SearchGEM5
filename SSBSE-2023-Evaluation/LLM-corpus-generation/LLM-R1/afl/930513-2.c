// Modification timestamp: 2023-08-14 13:33:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930513-2.c

#include <stdio.h>
#include <stdlib.h>

void sub3(const int *i) {
}

void eq(int a, int b) {
  static int i = 0;
  if (a != i)
    abort();
  i++;
}

int main(int argc, char *argv[]) {
  int i;

  for (i = 0; i < 4; i++) {
    const int j = i;
    int k;
    sub3(&j);
    k = j;
    eq(k, k);
  }
  exit(0);
}
