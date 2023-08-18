// Modification timestamp: 2023-08-14 17:25:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-004.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int32_t a, b;

union u {
  uint16_t c;
} d;

static int32_t *e = &b;
int64_t *f;
static int64_t **g = &f;
int64_t x;

int64_t h(int32_t i) {
  {
    x = i && (2036854775807 / a) && i;
    return x;
  }
}

void j() {
  for (; d.c; ++d.c)
    *e = h(**g);
}

int32_t h_call_argument_1;
int64_t y;

int main(int argc, char *argv[]) {
  if (argc != 8) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5> <val_6> <val_7>\n", argv[0]);
    return 1;
  }

  int64_t val_7 = atoi(argv[7]);
  int32_t val_6 = atoi(argv[6]);
  int64_t val_5 = atoi(argv[5]);
  int64_t val_4 = atoi(argv[4]);
  int64_t temp_1 = val_4;
  uint16_t val_3 = atoi(argv[3]);
  int32_t val_2 = atoi(argv[2]);
  int32_t val_1 = atoi(argv[1]);

  y = val_7;
  h_call_argument_1 = val_6;
  x = val_5;
  f = &temp_1;
  d.c = val_3;
  b = val_2;
  a = val_1;
  j();
  y = h(h_call_argument_1);

  printf("a = %" PRIi32 "\n", a);
  printf("b = %" PRIi32 "\n", b);
  printf("d.c = %" PRIu16 "\n", d.c);
  printf("y = %" PRIi64 "\n", y);
  printf("h_call_argument_1 = %" PRIi32 "\n", h_call_argument_1);
  printf("x = %" PRIi64 "\n", x);

  return 0;
}
