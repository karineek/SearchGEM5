// Modification timestamp: 2023-08-14 12:38:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021127-1.c

#include <stdio.h>
#include <stdlib.h>

long long llabs(long long b) {
  abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long a = atoll(argv[1]);

  if (llabs(a) != 1)
    abort();

  return 0;
}

Note: I added the atoll function to convert the command line argument to a long long.