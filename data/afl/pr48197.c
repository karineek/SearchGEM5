// Modification timestamp: 2023-08-14 15:16:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48197.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
static int y = 0x8000;

int main(int argc, char *argv[]) {
  unsigned int x = (short)y;

  if (sizeof (0LL) == sizeof (0U))
    return 0;

  if (0LL > (0U ^ (short)-0x8000))
    abort ();

  if (0LL > (0U ^ x))
    abort ();

  if (0LL > (0U ^ (short)y))
    abort ();

  if ((0U ^ (short)-0x8000) < 0LL)
    abort ();

  if ((0U ^ x) < 0LL)
    abort ();

  if ((0U ^ (short)y) < 0LL)
    abort ();

  return 0;
}

