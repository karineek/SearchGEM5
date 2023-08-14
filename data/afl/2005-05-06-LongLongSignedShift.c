
// Modification timestamp: 2023-08-10 15:55:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/llvm-test/2005-05-06-LongLongSignedShift.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int result = (x-100) >> 38;
  printf("%d\n", result);

  return 0;
}
