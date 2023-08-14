// Modification timestamp: 2023-08-14 15:59:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr84339.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct S { int a; char b[1]; };

__attribute__((noipa)) int
foo (struct S *p)
{
  return strlen (&p->b[0]);
}

__attribute__((noipa)) int
bar (struct S *p)
{
  return strlen (p->b);
}

int
main (int argc, char *argv[])
{
  struct S *p = malloc(sizeof(struct S) + 16);
  if (p)
    {
      p->a = atoi(argv[1]);
      strcpy(p->b, argv[2]);
      if (foo (p) != strlen(argv[2]) || bar (p) != strlen(argv[2]))
	abort ();
      free (p);
    }
  return 0;
}

