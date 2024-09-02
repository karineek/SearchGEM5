// Modification timestamp: 2023-08-14 17:26:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-009.c
#include <stdlib.h>

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

uint32_t a, b, h;
int16_t c, g;
uint8_t d = 8;
uint8_t *const e = &d;
int32_t *f;

void i(uint32_t val_1, uint32_t val_2, uint32_t val_3, int16_t val_4, int16_t val_5, int32_t val_6) {
  for (; c; c--) {
    g = 0;
    for (; g <= 8; g++) {
      h = ((b & a) ^ a ^ (b & a) ^ b) < b;
      *e ^= h;
      *f = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 8) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5> <val_6> <temp_1>\n", argv[0]);
    return 1;
  }

  uint32_t val_1 = atoi(argv[1]);
  uint32_t val_2 = atoi(argv[2]);
  uint32_t val_3 = atoi(argv[3]);
  int16_t val_4 = atoi(argv[4]);
  int16_t val_5 = atoi(argv[5]);
  int32_t val_6 = atoi(argv[6]);
  int32_t temp_1 = atoi(argv[7]);

  f = &temp_1;
  g = val_5;
  c = val_4;
  h = val_3;
  b = val_2;
  a = val_1;
  i(val_1, val_2, val_3, val_4, val_5, val_6);

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu32 "\n", b);
  printf("c = %" PRIi16 "\n", c);
  printf("d = %" PRIu8 "\n", d);
  printf("g = %" PRIi16 "\n", g);
  printf("h = %" PRIu32 "\n", h);

  return 0;
}


//Note: The values `val_1`, `val_2`, `val_3`, `val_4`, `val_5`, `val_6`, and `temp_1` are passed as command-line arguments to the program.