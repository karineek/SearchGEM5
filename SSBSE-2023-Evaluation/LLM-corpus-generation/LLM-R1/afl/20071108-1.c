// Modification timestamp: 2023-08-14 13:11:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20071108-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern void abort(void);
void *__builtin_memset(void *s, int c, size_t n);

struct S
{
  void *s1, *s2;
  unsigned char s3, s4, s5;
};

__attribute__((noinline)) void *foo(void)
{
  static struct S s;
  return &s;
}

__attribute__((noinline)) void *bar()
{
  return (void *)0;
}

__attribute__((noinline)) struct S *test(void *a, void *b)
{
  struct S *p, q;
  p = foo();
  if (p == 0)
  {
    p = &q;
    __builtin_memset(p, 0, sizeof(*p));
  }
  p->s1 = a;
  p->s2 = b;
  if (p == &q)
    p = 0;
  return p;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <arg1> <arg2>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  struct S *z = test((void *)&a, (void *)&b);
  if (z == 0 || z->s1 != (void *)&a || z->s2 != (void *)&b || z->s3 || z->s4)
    abort();
  return 0;
}
