// Modification timestamp: 2023-08-14 16:10:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/simd-2.c

#include <stdio.h>
#include <stdlib.h>

typedef short __attribute__((vector_size (16))) vecint;

vecint i;
vecint j;
vecint k;

union {
  vecint v;
  short i[8];
} res;

void verify(int a1, int a2, int a3, int a4,
            int b1, int b2, int b3, int b4) {
  if (a1 != b1 || a2 != b2 || a3 != b3 || a4 != b4)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <i1> <i2> <i3> <i4> <j1> <j2> <j3> <j4>\n", argv[0]);
    return 1;
  }

  i = (vecint){atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), 0, 0, 0, 0};
  j = (vecint){atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), 1, 1, 1, 1};

  k = i + j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 160, 113, 170, 230);

  k = i * j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 1500, 1300, 3000, 6000);

  k = i / j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 15, 7, 7, 6);

  k = i & j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 2, 4, 20, 8);

  k = i | j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 158, 109, 150, 222);

  k = i ^ j;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], 156, 105, 130, 214);

  k = -i;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], -150, -100, -150, -200);

  k = ~i;
  res.v = k;
  verify(res.i[0], res.i[1], res.i[2], res.i[3], -151, -101, -151, -201);

  return 0;
}
