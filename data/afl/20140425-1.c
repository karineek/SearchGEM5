// Modification timestamp: 2023-08-14 13:21:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140425-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

static void __attribute__((noinline))
set (unsigned long *l)
{
  *l = 31;
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long l;
  int i;

  set (&l);
  i = (int) l;
  l = (unsigned long)(2U << i);
  if (l != 0)
    abort ();
  return 0;
}
