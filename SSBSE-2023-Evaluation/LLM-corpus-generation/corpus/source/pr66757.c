// Modification timestamp: 2023-08-14 15:45:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66757.c

#include <stdio.h>
#include <stdlib.h>

int a, b;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  int t = (unsigned char) (~atoi(argv[2]));

  if ((t ^ 1) / 255)
    __builtin_abort();

  return 0;
}
