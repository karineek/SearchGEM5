// Modification timestamp: 2023-08-14 14:45:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-3.c

#include <stdio.h>
#include <stdlib.h>

void bar(int N) {
  int foo(char a[2][++N]) {
    N += 4;
    return sizeof(a[0]);
  }
  if (foo(0) != 2)
    abort();
  if (foo(0) != 7)
    abort();
  if (N != 11)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int N = atoi(argv[1]);
  bar(N);
  exit(0);
}
