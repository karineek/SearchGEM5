// Modification timestamp: 2023-08-14 15:12:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43784.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  unsigned char a[256];
};
union u {
  struct { struct s b; int c; } d;
  struct { int c; struct s b; } e;
};

static union u v;
static struct s *p = &v.d.b;
static struct s *q = &v.e.b;

static struct s __attribute__((noinline)) rp(void)
{
  return *p;
}

static void qp(void)
{
  *q = rp();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < 256; i++)
    p->a[i] = atoi(argv[1]);
  qp();
  for (i = 0; i < 256; i++)
    if (q->a[i] != atoi(argv[1]))
      __builtin_abort();
  return 0;
}
