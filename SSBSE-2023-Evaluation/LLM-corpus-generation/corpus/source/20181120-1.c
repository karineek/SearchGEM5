// Modification timestamp: 2023-08-14 13:24:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20181120-1.c

#include <stdio.h>
#include <stdlib.h>

int a, c, d;
volatile int b;
int *e = &d;

union U1 {
  unsigned f0;
  unsigned f1 : 15;
};
volatile union U1 u = { 0x4030201 };

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  for (c = 0; c <= x; c++) {
    union U1 f = { 0x4030201 };
    if (c == 1)
      b;
    *e = f.f1;
  }

  if (d != u.f1)
    __builtin_abort();

  return x;
}
