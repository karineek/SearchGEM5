// Modification timestamp: 2023-08-14 13:29:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920829-1.c

#include <stdio.h>
#include <stdlib.h>

long long c = 0LL;
long long c3 = 0LL;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  c = atoll(argv[1]);
  c3 = atoll(argv[2]);

  if (c * 3 != c3) {
    abort();
  }

  exit(0);
}
