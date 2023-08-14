// Modification timestamp: 2023-08-14 14:25:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/doloop-2.c
#include <limits.h>

extern void exit (int);
extern void abort (void);

volatile unsigned int i;

int
main (void)
{
  unsigned short z = 0;

  do ++i;
  while (--z > 0);
  if (i != USHRT_MAX + 1U)
    abort ();
  exit (0);
}
