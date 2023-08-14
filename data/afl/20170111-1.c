// Modification timestamp: 2023-08-14 13:22:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20170111-1.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  short a;
  long long b;
  short c;
  char d;
  unsigned short e;
  long *f;
};

static long foo (struct S *s) __attribute__((noclone, noinline));

static long foo (struct S *s)
{
  long a = 1;
  a /= s->e;
  s->f[a]--;
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long val = atoi(argv[1]);
  struct S s = { 0, 0, 0, 0, 2, &val };
  val = foo (&s);
  if (val != 0)
    abort ();
  return 0;
}
