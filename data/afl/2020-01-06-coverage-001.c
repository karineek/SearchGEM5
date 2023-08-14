// Modification timestamp: 2023-08-14 17:24:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-001.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t *a;
uint8_t b;
static int32_t **c = &a;
uint8_t *p;
int32_t x;

void d(uint8_t *e, int32_t *a) {
  **c &= 8;
  p = e;
  x = (*e &= 1) && *a && (*e = 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int32_t val_3;
  int8_t val_2;
  uint8_t temp_2;
  int32_t val_1;
  int32_t temp_1;

  val_1 = atoi(argv[1]);
  val_2 = -125;
  val_3 = -67108864;
  temp_1 = val_1;
  temp_2 = val_2;

  x = val_3;
  p = &temp_2;
  a = &temp_1;
  d(&temp_2, &temp_1);

  printf("b = %" PRIu8 "\n", b);
  printf("x = %" PRIi32 "\n", x);

  return 0;
}

