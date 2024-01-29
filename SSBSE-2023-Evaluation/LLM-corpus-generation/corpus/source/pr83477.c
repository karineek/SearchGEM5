// Modification timestamp: 2023-08-14 15:59:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr83477.c

#include <stdio.h>
#include <stdlib.h>

int yf = 0;

void pl(int q5, int nd) {
  unsigned int hp = q5;
  int zx = (q5 == 0) ? hp : (hp / q5);

  yf = ((nd < 2) * zx != 0) ? nd : 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int q5 = atoi(argv[1]);
  int nd = !yf;
  pl(q5, nd);
  if (yf != 1)
    __builtin_abort();

  return 0;
}
