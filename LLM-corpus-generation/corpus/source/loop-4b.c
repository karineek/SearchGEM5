// Modification timestamp: 2023-08-14 14:31:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-4b.c

#include <stdio.h>
#include <stdlib.h>

int f(int x) {
  int j = 1;
  long i;
  i = 0x60000000L;
  do {
    j <<= 1;
    i += 0x10000000L;
  } while (i < -0x60000000L);
  return j;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int result = f(atoi(argv[1]));
  if (result != 2) {
    abort();
  }
  exit(0);
}
