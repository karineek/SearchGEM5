// Modification timestamp: 2023-08-14 15:09:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42248.c

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

void check(Scf10 x, _Complex double y) {
  if (x.a != y) __builtin_abort();
}

void init(Scf10 *p, _Complex double y) {
  p->a = y;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  _Complex double val = (_Complex double) atof(argv[1]);

  init(&g1s, val);
  check(g1s, val);

  return 0;
}
