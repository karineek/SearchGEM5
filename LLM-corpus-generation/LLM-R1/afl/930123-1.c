// Modification timestamp: 2023-08-14 13:32:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930123-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int *x) {
  *x = 0;
}

int main(int argc, char *argv[]) {
  int s, c, x;
  char a[] = {0};

  f(&s);
  a[c = 0] = s == 0 ? (x=1, 'a') : (x=2, 'b');
  if (a[c] != 'a')
    abort();
  exit(0);
}
