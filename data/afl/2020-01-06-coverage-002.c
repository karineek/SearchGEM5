
// Modification timestamp: 2023-08-10 15:31:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/SignlessTypes/2020-01-06-coverage-002.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int32_t a, c, e;
int8_t b;
int16_t d;
int32_t x;
int64_t y;

int64_t f() {
  int32_t g = 0;
  x = g;
  for (; g < 5; g++)
    ;
  for (; g < 3; (void)g)
  h:
    for (;; (void)a)
      ;
  for (;; (void)b) {
    int32_t i;
    if (a)
      goto h;
    if (d) {
      if (e)
        return 0;
      break;
    }
    if (c)
      continue;
  }
  {
    y = 0;
    return y;
  };
}

int64_t z;

int32_t main(int argc, char *argv[]) {
  int64_t val_8;
  int64_t val_7;
  int32_t val_6;
  int16_t val_5;
  int8_t val_4;
  int32_t val_3;
  int32_t val_2;
  int32_t val_1;

  if (argc != 9) {
    printf("Usage: %s <val_1> <val_2> <val_3> <val_4> <val_5> <val_6> <val_7> <val_8>\n", argv[0]);
    return 1;
  }

  val_1 = atoi(argv[1]);
  val_2 = atoi(argv[2]);
  val_3 = atoi(argv[3]);
  val_4 = atoi(argv[4]);
  val_5 = atoi(argv[5]);
  val_6 = atoi(argv[6]);
  val_7 = atoi(argv[7]);
  val_8 = atoi(argv[8]);

  z = val_8;
  y = val_7;
  x = val_6;
  d = val_5;
  b = val_4;
  e = val_3;
  c = val_2;
  a = val_1;
  z = f();

  printf("a = %" PRIi32 "\n", a);
  printf("b = %" PRIi8 "\n", b);
  printf("c = %" PRIi32 "\n", c);
  printf("d = %" PRIi16 "\n", d);
  printf("x = %" PRIi32 "\n", x);
  printf("e = %" PRIi32 "\n", e);
  printf("z = %" PRIi64 "\n", z);
  printf("y = %" PRIi64 "\n", y);

  return 0;
}
