// Modification timestamp: 2023-08-14 14:45:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22061-4.c

#include <stdio.h>
#include <stdlib.h>

void foo(int a[2][int N]) {}

void bar(int N) {
  int a[2][N];
  foo(a);
  int b[2][N];
  foo(b);
  if (sizeof(a) != sizeof(int) * 2 * 1)
    abort();
  if (sizeof(b) != sizeof(int) * 2 * 2)
    abort();
  if (N != 3)
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
