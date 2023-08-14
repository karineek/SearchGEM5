
// Modification timestamp: 2023-08-10 15:15:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2006-12-07-Compare64BitConstant.c

#include <stdio.h>
#include <stdlib.h>

long long Large = 5LL << 48;

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long arg = atoll(argv[1]);

  // Make sure large constants compare correctly.
  if (((arg >> 48) & 7LL) == 5LL) {
    printf("Works.\n");
  } else {
    printf("Doesn\'t.\n");
  }
  return 0;
}
