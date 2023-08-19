// Modification timestamp: 2023-08-14 14:55:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33992.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

void __attribute__((noinline))
bar (unsigned long long i)
{
  if (i)
    abort ();
}

static void __attribute__((always_inline))
foo (unsigned long long *r)
{
  int i;

  for (i = 0; ; i++)
    if (*r & ((unsigned long long)1 << (63 - i)))
      break;

  bar (i);
}

void __attribute__((noinline))
do_test (unsigned long long *r)
{
  int i;

  for (i = 0; i < 2; ++i)
    foo (r);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long long r = strtoull(argv[1], NULL, 0);
  do_test(&r);
  return 0;
}
