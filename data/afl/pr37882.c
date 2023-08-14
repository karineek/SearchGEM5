// Modification timestamp: 2023-08-14 15:00:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37882.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  unsigned char b : 3;
} s;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s.b = atoi(argv[1]);
  if (s.b > 0 && s.b < 4)
    abort();
  return 0;
}
