// Modification timestamp: 2023-08-14 16:52:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-aliasing-1.c

#include <stdio.h>
#include <stdlib.h>

struct S { float f; };

int __attribute__((noinline)) foo (int *r, struct S *p) {
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0;
  return i + *q;
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  if (foo(&i, (struct S *)&i) != 1)
    abort();

  return 0;
}
