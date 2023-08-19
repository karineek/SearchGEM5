// Modification timestamp: 2023-08-14 13:00:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050104-1.c

#include <stdio.h>
#include <stdlib.h>

void abort (void);

static long long min(long long j) {
  return -j - 1;
}

void foo (long long j) {
  if (j > 10 || j < min(j))
    abort ();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long j = atoi(argv[1]);
  foo(j);
  return 0;
}
