// Modification timestamp: 2023-08-14 16:10:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/simd-6.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int memcmp(const void *, const void *, __SIZE_TYPE__);

typedef unsigned char v8qi __attribute__((vector_size(8)));

v8qi foo(v8qi x, v8qi y)
{
  return x * y;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  v8qi a = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8])};
  v8qi b = {atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]), atoi(argv[13]), atoi(argv[14]), atoi(argv[15]), atoi(argv[16])};
  v8qi c = {atoi(argv[17]), atoi(argv[18]), atoi(argv[19]), atoi(argv[20]), atoi(argv[21]), atoi(argv[22]), atoi(argv[23]), atoi(argv[24])};
  v8qi r;

  r = foo(a, b);
  if (memcmp(&r, &c, 8) != 0)
    abort();

  return 0;
}
