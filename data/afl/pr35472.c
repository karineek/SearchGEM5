// Modification timestamp: 2023-08-14 14:57:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35472.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S { int i[16]; };
struct S *p;

extern void abort(void);
extern void *memset(void *s, int c, size_t n);
void __attribute__((noinline,noclone))
foo(struct S *a, struct S *b) { a->i[0] = -1; p = b; }

void test(void)
{
  struct S a, b;
  memset(&a.i[0], '\0', sizeof(a.i));
  memset(&b.i[0], '\0', sizeof(b.i));
  foo(&a, &b);
  *p = a;
  *p = b;
  if (b.i[0] != -1)
    abort();
}

int main(int argc, char *argv[])
{
  test();
  return 0;
}
