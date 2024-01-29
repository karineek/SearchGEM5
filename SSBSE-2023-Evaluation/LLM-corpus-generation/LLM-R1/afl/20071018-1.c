// Modification timestamp: 2023-08-14 13:10:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071018-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct foo {
  int rank;
  char *name;
};

struct mem {
  struct foo *x[4];
};

void __attribute__((noinline)) bar(struct foo **f)
{
  *f = __builtin_malloc(sizeof(struct foo));
}
struct foo * __attribute__((noinline, noclone)) foo(int rank)
{
  void *x = __builtin_malloc(sizeof(struct mem));
  struct mem *as = x;
  struct foo **upper = &as->x[rank * 8 - 5];
  *upper = 0;
  bar(upper);
  return *upper;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (foo(atoi(argv[1])) == 0)
    abort ();
  return 0;
}
