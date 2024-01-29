// Modification timestamp: 2023-08-14 17:16:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-08-20-FoldBug.c
/* This testcase checks for a bug in the GCC front-end to make sure it's not
   folding expressions incorrectly */

#include <stdio.h>
extern void abort (void);
int
foo (int x)
{
  if ((int) (x & 0x80ffffff) != (int) (0x8000fffe))
    abort ();

  return 0;
}
int main () {
  foo (0x8000fffe);
  printf("All ok\n");
  return 0;
}

