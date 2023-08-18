// Modification timestamp: 2023-08-14 11:59:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010711-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(int *a) {}

int main(int argc, char *argv[]) {
  int a;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (atoi(argv[1]) == 0) {
    abort();
  } else {
    foo(&a);
    exit(0);
  }
}
