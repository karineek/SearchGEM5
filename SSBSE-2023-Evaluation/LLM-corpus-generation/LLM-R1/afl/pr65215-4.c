// Modification timestamp: 2023-08-14 15:42:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65215-4.c

#include <stdio.h>

struct S { unsigned long long l1 : 48; };

static inline unsigned int
foo (unsigned int x)
{
  return (x >> 24) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) | (x << 24);
}

__attribute__((noinline, noclone)) unsigned int
bar (struct S *x)
{
  return foo (x->l1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  if (__CHAR_BIT__ != 8 || sizeof (unsigned int) != 4 || sizeof (unsigned long long) != 8)
    return 0;
  struct S s;
  s.l1 = foo (atoi(argv[1])) | (0xfeedULL << 32);
  if (bar (&s) != atoi(argv[1]))
    __builtin_abort ();
  return 0;
}
