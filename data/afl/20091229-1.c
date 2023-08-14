// Modification timestamp: 2023-08-14 13:17:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20091229-1.c

#include <stdio.h>
#include <stdlib.h>

long long foo(long long v) {
  return v / -0x080000000LL;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long v = atoll(argv[1]);
  if (foo(v) != -1) abort();
  exit(0);
}
