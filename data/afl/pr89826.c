// Modification timestamp: 2023-08-14 16:05:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr89826.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
typedef unsigned long long u64;

u64 a;
u32 b;

u64 foo(u32 d) {
  a -= d ? 0 : ~a;
  return a + b;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  u64 x = foo(atoi(argv[1]));
  if (x != 0)
    abort();
  return 0;
}

