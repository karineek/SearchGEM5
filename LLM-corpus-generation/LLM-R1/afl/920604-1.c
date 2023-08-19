// Modification timestamp: 2023-08-14 13:27:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920604-1.c

#include <stdio.h>
#include <stdlib.h>

long long mod(long long a, long long b) {
  return a % b;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long long a = atoll(argv[1]);
  long long b = atoll(argv[2]);
  mod(a, b);
  exit(0);
}
