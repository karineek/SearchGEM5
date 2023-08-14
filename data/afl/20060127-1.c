// Modification timestamp: 2023-08-14 13:06:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060127-1.c

#include <stdio.h>
#include <stdlib.h>

void abort();

void f(long long a) {
  if ((a & 0xffffffffLL) != 0)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long a = atoi(argv[1]);
  f(a);

  return 0;
}
