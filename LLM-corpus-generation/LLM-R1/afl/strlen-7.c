// Modification timestamp: 2023-08-14 16:51:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strlen-7.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct A { int i; char a[1]; void (*p)(); };
struct B { char a[sizeof (struct A) - __builtin_offsetof (struct A, a)]; };

__attribute__ ((noipa)) void
init (char *d, const char *s)
{
  strcpy (d, s);
}

struct B b;

__attribute__ ((noipa)) void
test_dynamic_type (struct A *p)
{
  char *q = (char*)memcpy (p->a, &b, sizeof b);

  init (q, "foobar");

  if (6 != strlen (q))
    abort();
}

int main (void)
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct A *p = (struct A*)malloc (sizeof *p);
  test_dynamic_type (p);
  return 0;
}

