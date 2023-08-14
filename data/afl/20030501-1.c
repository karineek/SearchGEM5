// Modification timestamp: 2023-08-14 12:45:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030501-1.c

#include <stdio.h>
#include <stdlib.h>

int retframe_block(int size) {
  return size + 5;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int size = atoi(argv[1]);

  if (retframe_block(size) != 15)
    abort();
  exit(0);
}
