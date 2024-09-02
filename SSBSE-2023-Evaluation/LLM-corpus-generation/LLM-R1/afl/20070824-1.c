// Modification timestamp: 2023-08-14 13:09:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070824-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S
{
  struct S *a;
  int b;
};

int main(int argc, char *argv[]) {
  struct S *s = (struct S *)0, **p, *n;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  for (p = &s; *p; p = &(*p)->a);
  n = (struct S *)__builtin_alloca(sizeof(*n));
  n->a = *p;
  n->b = atoi(argv[1]);
  *p = n;

  if (!s)
    abort();
  return 0;
}
