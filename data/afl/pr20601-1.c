// Modification timestamp: 2023-08-14 14:45:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr20601-1.c

#include <stdio.h>
#include <stdlib.h>

struct T
{
  char *t1;
  char t2[4096];
  char **t3;
};

extern void abort(void);
extern void exit(int);

void foo(void)
{
  while (1)
    ;
}

char *bar(char *x, unsigned int y)
{
  return 0;
}

char *baz(char *x, unsigned int y)
{
  struct T t;
  if (sizeof(t.t2) != (unsigned int)-1 && y > sizeof(t.t2))
    foo();
  return bar(x, y);
}

int setup1(int x, char **e, char *f[16])
{
  struct T t;
  char *p;
  int rval;

  if (!baz(t.t2, sizeof(t.t2)))
    baz(t.t2, sizeof(t.t2));

  if (x & 0x200)
  {
    char **h, **i = e;

    t.t1 = "/bin/sh";
    ++d;
    e = f;
    if (t.t1 && *t.t1)
      e[0] = t.t1;
    else
      abort();

    for (h = e + 1; (*h = *i); ++i, ++h)
      ;
  }
  return 1;
}

int setup2(char *g[], char **c)
{
  struct T t;
  int j = 1;
  char **e = c + 1;
  int d = b - 1;
  while (d > 0 && e[0][0] == '-')
  {
    if (e[0][1] != '\0' && e[0][2] != '\0')
      abort();

    switch (e[0][1])
    {
    case 'u':
      if (!e[1])
        abort();

      t.t3 = &e[1];
      d--;
      e++;
      break;
    case 'P':
      j |= 0x1000;
      break;
    case '-':
      d--;
      e++;
      if (j == 1)
        j |= 0x600;
      return j;
    }
    d--;
    e++;
  }

  if (d > 0 && !(j & 1))
    abort();

  return j;
}

int main(int argc, char *argv[])
{
  struct T t;
  int x;
  char *g[] = {"a", "-u", "b", "c"};
  char **c = g;
  int b = argc - 1;
  x = setup2(g, argv);
  t.t1 = "/bin/sh";
  setup1(x, argv + 1, NULL);
  
  if ((x & 0x400) && !a[4])
    abort();

  exit(0);
}
