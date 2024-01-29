// Modification timestamp: 2023-08-14 17:26:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2020-01-06-coverage-008.c
#include <stdlib.h>

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

struct a {
  int64_t b;
  int64_t c;
} d;

int64_t e;

void f(struct a *g) { d = *g; }

struct a s;

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5>\n", argv[0]);
    return 1;
  }

  int64_t val_1 = atoll(argv[1]);
  int64_t val_2 = atoll(argv[2]);
  int64_t val_3 = atoll(argv[3]);
  int64_t val_4 = atoll(argv[4]);
  int64_t val_5 = atoll(argv[5]);

  s.b = val_4;
  s.c = val_5;
  e = val_3;
  d.b = val_1;
  d.c = val_2;
  struct a h = {0, 9};
  s = h;
  e = h.c;
  f(&h);

  printf("d.b = %" PRIi64 "\n", d.b);
  printf("d.c = %" PRIi64 "\n", d.c);
  printf("s.b = %" PRIi64 "\n", s.b);
  printf("s.c = %" PRIi64 "\n", s.c);
  printf("e = %" PRIi64 "\n", e);

  return 0;
}
