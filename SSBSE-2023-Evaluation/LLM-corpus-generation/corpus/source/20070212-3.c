// Modification timestamp: 2023-08-14 13:08:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070212-3.c

#include <stdio.h>
#include <stdlib.h>

struct foo { int i; int j; };

int bar(struct foo *k, int k2, int f, int f2) {
  int *p, *q;
  int res;
  if (f)
    p = &k->i;
  else
    p = &k->j;
  res = *p;
  k->i = 1;
  if (f2)
    q = p;
  else
    q = &k2;
  return res + *q;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct foo k;
  k.i = atoi(argv[1]);
  k.j = atoi(argv[2]);
  if (bar(&k, atoi(argv[3]), atoi(argv[4]), atoi(argv[5])) != atoi(argv[6])) {
    abort();
  }
  return 0;
}
