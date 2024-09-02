// Modification timestamp: 2023-08-14 13:03:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050604-1.c
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef unsigned short v4hi __attribute__((vector_size(8)));
typedef float v4sf __attribute__((vector_size(16)));

union
{
  v4hi v;
  short s[4];
} u;

union
{
  v4sf v;
  float f[4];
} v;

void foo(unsigned int i)
{
  if (i < 2)
  {
    u.v += (v4hi){12, 32768};
    foo(i + 1);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int i = atoi(argv[1]);
  foo(i);

  if (u.s[0] != 24 || u.s[1] != 0 || u.s[2] || u.s[3])
    abort();
  if (v.f[0] != 36.0 || v.f[1] != 40.0 || v.f[2] != 44.0 || v.f[3] != 0.0)
    abort();
  return 0;
}
