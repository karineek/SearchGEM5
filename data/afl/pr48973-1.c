// Modification timestamp: 2023-08-14 15:17:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48973-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

struct S { int f: 1; } s;
int v = -1;

void foo(unsigned int x) {
  if (x != -1U)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s.f = (v & 1) > 0;
  foo(atoi(argv[1]));

  return 0;
}
