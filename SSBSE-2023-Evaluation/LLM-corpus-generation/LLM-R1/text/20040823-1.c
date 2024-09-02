// Modification timestamp: 2023-08-14 12:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040823-1.c
/* Ensure that we create VUSE operands also for noreturn functions.  */

#include <stdlib.h>
#include <string.h>

int *pwarn;

void bla (void) __attribute__ ((noreturn));

void bla (void)
{
  if (!*pwarn)
    abort ();

  exit (0);
}

int main (void)
{
  int warn;

  memset (&warn, 0, sizeof (warn));

  pwarn = &warn;

  warn = 1;

  bla ();
}
