// Modification timestamp: 2023-08-14 13:14:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080522-1.c

#include <stdio.h>
#include <stdlib.h>

static int i;
static int *p = &i;

int __attribute__((noinline))
foo(int *q)
{
  *p = 1;
  *q = 2;
  return *p;
}

int __attribute__((noinline))
bar(int *q)
{
  *q = 2;
  *p = 1;
  return *q;
}

int main()
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int j = atoi(argv[1]);

  if (foo(&i) != 2)
    abort ();
  if (bar(&i) != 1)
    abort ();
  if (foo(&j) != 1)
    abort ();
  if (j != 2)
    abort ();
  if (bar(&j) != 2)
    abort ();
  if (j != 2)
    abort ();

  return 0;
}
