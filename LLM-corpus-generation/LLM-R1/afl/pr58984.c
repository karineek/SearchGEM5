// Modification timestamp: 2023-08-14 15:35:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58984.c

#include <stdio.h>
#include <stdlib.h>

struct S { int f0 : 8; int : 6; int f1 : 5; };
struct T { char f0; int : 6; int f1 : 5; };

int a, *c = &a, e, n, b, m;

static int
foo (struct S p)
{
  const unsigned short *f[36];
  for (; e < 2; e++)
    {
      const unsigned short **i = &f[0];
      *c ^= 1;
      if (p.f1)
	{
	  *i = 0;
	  return b;
	}
    }
  return 0;
}

static int
bar (struct T p)
{
  const unsigned short *f[36];
  for (; e < 2; e++)
    {
      const unsigned short **i = &f[0];
      *c ^= 1;
      if (p.f1)
	{
	  *i = 0;
	  return b;
	}
    }
  return 0;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S o = { atoi(argv[1]), atoi(argv[2]) };
  foo (o);
  m = n || o.f0;
  if (a != 1)
    __builtin_abort ();
  e = 0;
  struct T p = { atoi(argv[3]), atoi(argv[4]) };
  bar (p);
  m |= n || p.f0;
  if (a != 0)
    __builtin_abort ();
  return 0;
}
