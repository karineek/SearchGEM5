// Modification timestamp: 2023-08-14 13:23:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20171008-1.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  char c1, c2, c3, c4;
} __attribute__((aligned(4)));

static char bar (char **p) __attribute__((noclone, noinline));
static struct S foo (void) __attribute__((noclone, noinline));

int i;

static char
bar (char **p)
{
  i = 1;
  return 0;
}

static struct S
foo (void)
{
  struct S ret;
  char r, s, c1, c2;
  char *p = &r;
  
  int argc = 0;
  char **argv = NULL;
  
  s = bar (&p);
  if (s)
    c2 = *p;
  c1 = 0;
  
  ret.c1 = c1;
  ret.c2 = c2;

  return ret;
}

int main (int argc, char *argv[])
{
  struct S s = foo ();
  if (s.c1 != 0)
    __builtin_abort ();
  return 0;
}

