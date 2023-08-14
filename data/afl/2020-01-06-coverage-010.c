// Modification timestamp: 2023-08-14 17:26:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-010.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int32_t *a;
int32_t b, d, f;
int8_t c;
volatile int32_t e;
int32_t x;
int8_t *p;
int32_t y;
int32_t z;
int32_t w;

static int32_t j(int32_t h, int8_t* g) {
  x = h;
  for (; b;) {
    f = 0;
    for (; f <= 9; f++) {
      int32_t *i = &h;
      p = g;
      y = (*i)++ && (*g = 0);
      z = e;
    }
    *a = 0;
  }
  {
    w = d;
    return w;
  };
}

int32_t v;

void k() { v = j(5, &c); }

int main(int argc, char *argv[]) {
  if (argc != 14) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5> <val_6> <val_7> <val_8> <val_9> <val_10> <val_11> <val_12> <b>\n", argv[0]);
    return 1;
  }

  int32_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);
  int32_t val_3 = atoi(argv[3]);
  int32_t val_4 = atoi(argv[4]);
  int8_t val_5 = atoi(argv[5]);
  int32_t val_6 = atoi(argv[6]);
  int32_t val_7 = atoi(argv[7]);
  int8_t val_8 = atoi(argv[8]);
  int32_t val_9 = atoi(argv[9]);
  int32_t val_10 = atoi(argv[10]);
  int32_t val_11 = atoi(argv[11]);
  int32_t val_12 = atoi(argv[12]);
  b = atoi(argv[13]);

  int32_t temp_1 = val_1;
  int8_t temp_2 = val_8;

  v = val_12;
  w = val_11;
  z = val_10;
  y = val_9;
  p = &temp_2;
  x = val_7;
  e = val_6;
  c = val_5;
  f = val_4;
  d = val_3;
  a = &temp_1;
  k();

  printf("b = %" PRIi32 "\n", b);
  printf("c = %" PRIi8 "\n", c);
  printf("d = %" PRIi32 "\n", d);
  printf("x = %" PRIi32 "\n", x);
  printf("e = %" PRIi32 "\n", e);
  printf("y = %" PRIi32 "\n", y);
  printf("z = %" PRIi32 "\n", z);
  printf("v = %" PRIi32 "\n", v);
  printf("f = %" PRIi32 "\n", f);
  printf("w = %" PRIi32 "\n", w);

  return 0;
}
