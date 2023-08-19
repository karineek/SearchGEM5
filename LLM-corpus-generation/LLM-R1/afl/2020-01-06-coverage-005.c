// Modification timestamp: 2023-08-14 17:25:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-005.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint32_t a, c, d;
uint64_t b;
int16_t e;
uint64_t *p;
int16_t *q;
void g();
uint64_t *r;

void h() {
  uint64_t *f = &b;
  r = f;
  *f = 6;
  g();
}

uint64_t *s;
int16_t *t;

void g() {
i : {
  uint64_t *j = &b;
  s = j;
  p = j;
  int16_t *k = &e;
  t = k;
  q = k;
  --*k;
  *j &= c;
}
  for (; d; a = d)
    if (e)
      goto i;
}

int main(int argc, char *argv[]) {
  if (argc != 12) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5> <val_6> <val_7> <val_8> <val_9> <val_10>\n", argv[0]);
    return 1;
  }

  int32_t val_1 = atoi(argv[1]);
  int32_t val_2 = atoi(argv[2]);
  int32_t val_3 = atoi(argv[3]);
  int64_t val_4 = atoll(argv[4]);
  int16_t val_5 = atoi(argv[5]);
  int64_t val_6 = atoll(argv[6]);
  int16_t val_7 = atoi(argv[7]);
  int64_t val_8 = atoll(argv[8]);
  int64_t val_9 = atoll(argv[9]);
  int16_t val_10 = atoi(argv[10]);

  uint64_t temp_1 = val_6;
  int16_t temp_2 = val_7;
  uint64_t temp_3 = val_8;
  uint64_t temp_4 = val_9;
  int16_t temp_5 = val_10;

  t = &temp_5;
  s = &temp_4;
  r = &temp_3;
  q = &temp_2;
  p = &temp_1;
  e = val_5;
  b = val_4;
  d = val_3;
  c = val_2;
  a = val_1;
  h();
  g();

  printf("a = %" PRIu32 "\n", a);
  printf("b = %" PRIu64 "\n", b);
  printf("c = %" PRIu32 "\n", c);
  printf("d = %" PRIu32 "\n", d);
  printf("e = %" PRIi16 "\n", e);

  return 0;
}
