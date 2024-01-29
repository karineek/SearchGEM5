// Modification timestamp: 2023-08-14 13:38:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-5.c

#include <stdio.h>
#include <stdlib.h>

struct tiny {
  short c;
  short d;
};

void f(int n, struct tiny x, struct tiny y, struct tiny z, long l) {
  if (x.c != 10)
    abort();
  if (x.d != 20)
    abort();

  if (y.c != 11)
    abort();
  if (y.d != 21)
    abort();

  if (z.c != 12)
    abort();
  if (z.d != 22)
    abort();

  if (l != 123)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct tiny x[3];
  x[0].c = atoi(argv[1]);
  x[1].c = atoi(argv[2]);
  x[2].c = atoi(argv[3]);
  x[0].d = atoi(argv[4]);
  x[1].d = atoi(argv[5]);
  x[2].d = atoi(argv[6]);

  f(3, x[0], x[1], x[2], (long) atoi(argv[7]));
  exit(0);
}
