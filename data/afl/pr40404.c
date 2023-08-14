// Modification timestamp: 2023-08-14 15:06:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40404.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  unsigned int ui17 : 17;
} s;

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x = atoi(argv[1]);
  s.ui17 = x;
  if (s.ui17 >= 0xfffffffeu)
    abort();

  return 0;
}
