// Modification timestamp: 2023-08-14 13:40:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941014-2.c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned short a;
  unsigned short b;
} foo_t;

void a1 (unsigned long offset) {}

volatile foo_t *
f ()
{
  volatile foo_t *foo_p = (volatile foo_t *)malloc (sizeof (foo_t));

  a1((unsigned long)foo_p-30);
  if (foo_p->a & 0xf000)
    printf("%d\n", foo_p->a);
  foo_p->b = 0x0100;
  a1 ((unsigned long)foo_p + 2);
  a1 ((unsigned long)foo_p - 30);
  return foo_p;
}

main ()
{
  volatile foo_t *foo_p;

  foo_p = f ();
  if (foo_p->b != 0x0100)
    abort ();
  exit (0);
}
