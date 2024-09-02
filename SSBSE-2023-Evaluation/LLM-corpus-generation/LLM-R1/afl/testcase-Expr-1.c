// Modification timestamp: 2023-08-14 17:30:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-Expr-1.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t arr[3] = {[2] = 2, [0] = 0, [1] = 1};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int32_t arg0 = atoi(argv[1]);
  printf("%" PRId32, arr[arg0]);
  if (0)
    return 1;
  if (arr[arg0] != -5)
    return 2;
  if (arr[arg0 + 1] != 2)
    return 3;
  return 0;
}
