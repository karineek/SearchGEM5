// Modification timestamp: 2023-08-14 15:11:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43008.c

#include <stdio.h>
#include <stdlib.h>

int i;

struct X {
  int *p;
};

struct X * __attribute__((malloc))
my_alloc(void) {
  struct X *p = __builtin_malloc(sizeof(struct X));
  p->p = &i;
  return p;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  struct X *p, *q;
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  i = atoi(argv[1]);
  p = my_alloc();
  q = my_alloc();
  *(p->p) = 1;
  *(q->p) = 0;
  if (*(p->p) != 0)
    abort();
  return 0;
}
