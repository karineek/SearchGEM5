// Modification timestamp: 2023-08-14 17:31:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-14-initialize-string.c

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char title[] = argv[1];
  printf("%s", title);
  return 0;
}
