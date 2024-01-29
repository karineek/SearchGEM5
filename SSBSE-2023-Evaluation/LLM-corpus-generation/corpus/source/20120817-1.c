// Modification timestamp: 2023-08-14 13:20:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120817-1.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

unsigned long foo = 0;

u64 f(u64 foo) {
  return ((u64)40) + ((u64) 24) * (int)(foo - 1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long foo = atoi(argv[1]);

  if (f(foo) != 16)
    abort();

  exit(0);
}
