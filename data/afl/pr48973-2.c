// Modification timestamp: 2023-08-14 15:17:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48973-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S {
  int f : 1;
} s;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int v = atoi(argv[1]);
  s.f = v < 0;
  if ((unsigned int)s.f != -1U)
    abort();

  return 0;
}
