// Modification timestamp: 2023-08-14 17:25:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-003.c
#include <stdlib.h>

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int8_t a;
int32_t x;

void b(int8_t arg_1, int32_t arg_2) {
  x = (uint64_t)4073709551607 > arg_1 || arg_1 != 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int8_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);

  a = val_1;
  x = val_2;
  b(a, x);

  printf("a = %" PRIi8 "\n", a);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}
