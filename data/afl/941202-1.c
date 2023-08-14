// Modification timestamp: 2023-08-14 13:41:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941202-1.c

#include <stdio.h>
#include <stdlib.h>

void g(int x, int y) {
  if (x != 3)
    abort();
}

void f(int i) {
  int* tmp;
  tmp = (int*)malloc(sizeof(i));
  *tmp = i;
  g(*tmp, 0);
  free(tmp);
}

int main(int argc, char *argv[]) {
  f(3);
  exit(0);
}
