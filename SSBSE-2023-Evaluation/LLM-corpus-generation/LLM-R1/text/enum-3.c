// Modification timestamp: 2023-08-14 14:26:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/enum-3.c
/* The composite type of int and an enum compatible with int might be
   either of the two types, but it isn't an unsigned type.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */

#include <limits.h>

#include <stdio.h>

extern void abort (void);
extern void exit (int);

enum e { a = INT_MIN };

int *p;
enum e *q;
int
main (void)
{
  enum e x = a;
  q = &x;
  if (*(1 ? q : p) > 0)
    abort ();
  exit (0);
}
