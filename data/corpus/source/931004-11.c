// Modification timestamp: 2023-08-14 13:36:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931004-11.c

#include <stdio.h>
#include <stdlib.h>

struct tiny {
  char c;
  char d;
  char e;
};

void f(int n, struct tiny x, struct tiny y, struct tiny z, long l) {
  if (x.c != 10)
    abort();
  if (x.d != 20)
    abort();
  if (x.e != 30)
    abort();

  if (y.c != 11)
    abort();
  if (y.d != 21)
    abort();
  if (y.e != 31)
    abort();

  if (z.c != 12)
    abort();
  if (z.d != 22)
    abort();
  if (z.e != 32)
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
  x[0].e = atoi(argv[7]);
  x[1].e = atoi(argv[8]);
  x[2].e = atoi(argv[9]);
  f(3, x[0], x[1], x[2], atol(argv[10]));
  exit(0);
}
