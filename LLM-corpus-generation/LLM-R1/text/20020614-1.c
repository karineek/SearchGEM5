// Modification timestamp: 2023-08-14 12:35:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020614-1.c
/* PR c/6677 */
/* Verify that GCC doesn't perform illegal simplifications
   when folding constants.  */

#include <limits.h>

extern void abort (void);
extern void exit (int);

int main (void)
{
  int i;
  signed char j;
  unsigned char k;

  i = SCHAR_MAX;

  j = ((signed char) (i << 1)) / 2;

  if (j != -1)
    abort();

  j = ((signed char) (i * 2)) / 2;

  if (j != -1)
    abort();

  i = UCHAR_MAX;

  k = ((unsigned char) (i << 1)) / 2;

  if (k != UCHAR_MAX/2)
    abort();

  k = ((unsigned char) (i * 2)) / 2;

  if (k != UCHAR_MAX/2)
    abort();

  exit(0);
}
