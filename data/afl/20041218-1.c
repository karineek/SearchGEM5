// Modification timestamp: 2023-08-14 13:00:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041218-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct T
{
  unsigned int b, c, *d;
  unsigned char e;
};
struct S
{
  unsigned int a;
  struct T f;
};
struct U
{
  struct S g, h;
};
struct V
{
  unsigned int i;
  struct U j;
};

extern void exit (int);
extern void abort (void);

void *
dummy1 (void *x)
{
  return "";
}

void *
dummy2 (void *x, void *y)
{
  exit (0);
}

struct V *
baz (unsigned int x)
{
  static struct V v;
  memset(&v, 0x55, sizeof(v));
  return &v;
}

int
check (void *x, struct S *y)
{
  if (y->a || y->f.b || y->f.c || y->f.d || y->f.e)
    abort ();
  return 1;
}

static struct V *
bar (unsigned int x, void *y)
{
  const struct T t = { 0, 0, (void *) 0, 0 };
  struct V *u;
  void *v;
  v = dummy1 (y);
  if (!v)
    return (void *) 0;

  u = baz (sizeof (struct V));
  u->i = x;
  u->j.g.a = 0;
  u->j.g.f = t;
  u->j.h.a = 0;
  u->j.h.f = t;

  if (!check (v, &u->j.g) || !check (v, &u->j.h))
    return (void *) 0;
  return u;
}

int
foo (unsigned int *x, unsigned int y, void **z)
{
  void *v;
  unsigned int i, j;

  *z = v = (void *) 0;

  for (i = 0; i < y; i++)
    {
      struct V *c;

      j = *x;

      switch (j)
    {
    case 1:
      c = bar (j, x);
      break;
    default:
      c = 0;
      break;
    }
      if (c)
    v = dummy2 (v, c);
      else
        return 1;
    }

  *z = v;
  return 0;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int one = atoi(argv[1]);
  void *p;
  foo (&one, 1, &p);
  abort ();
}
