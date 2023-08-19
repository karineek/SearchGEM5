// Modification timestamp: 2023-08-14 17:18:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2006-12-07-Compare64BitConstant.c

#include <stdio.h>

long long Large = 5LL << 48;

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  if (((arg >> 48) & 7LL) == 5LL) {
    printf("Works.\n");
  } else {
    printf("Doesn\'t.\n");
  }
  return 0;
}
