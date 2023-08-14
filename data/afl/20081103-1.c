// Modification timestamp: 2023-08-14 13:15:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20081103-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S {
  char c;
  char arr[4];
  float f;
};

char A[4] = { '1', '2', '3', '4' };

void foo(struct S s) {
  if (memcmp(s.arr, A, 4)) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  struct S s;
  memcpy(s.arr, A, 4);
  foo(s);
  return x;
}
