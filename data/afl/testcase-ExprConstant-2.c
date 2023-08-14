c
// Modification timestamp: 2023-08-10 15:49:31
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  printf("%s\n", _Generic(i + (2L + 42), long
                          : "long", int
                          : "int", long long
                          : "long long"));
  return 0;
}
