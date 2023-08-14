// Modification timestamp: 2023-08-14 17:25:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-007.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t a;
const uint32_t b = -1L, c;
int16_t d;

void e(uint32_t arg1, uint32_t arg2, int16_t arg3) {
  uint32_t f;
  uint32_t g;
  f = arg2 / arg1;
  g = f;
  arg3 = g < c;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <val_1> <val_2> <arg3>\n", argv[0]);
    return 1;
  }

  uint32_t arg1 = atoi(argv[1]);
  int16_t arg3 = atoi(argv[3]);
  uint32_t val_1 = arg1;
  int16_t val_2 = atoi(argv[2]);

  d = val_2;
  a = val_1;
  e(arg1, val_2, arg3);

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu32 "\n", b);
  printf("c = %" PRIu32 "\n", c);
  printf("d = %" PRIi16 "\n", d);

  return 0;
}

