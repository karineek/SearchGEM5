// Modification timestamp: 2023-08-14 13:06:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060412-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S {
  long o;
};

struct T {
  long o;
  struct S m[82];
};

struct T t;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct S *p, *q;

  p = (struct S *)&t;
  p = &((struct T *)p)->m[0];
  q = p + atoi(argv[1]);
  while (--q > p)
    q->o = -1;
  q->o = 0;

  if (q > p)
    abort();
  if (q - p > 0)
    abort();
  return 0;
}
