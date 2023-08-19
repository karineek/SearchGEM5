// Modification timestamp: 2023-08-14 13:47:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961125-1.c

#include <stdio.h>
#include <stdlib.h>

static char *
begfield (char tab, char *ptr, char *lim, int sword, int schar)
{
  if (tab)
  {
    while (ptr < lim && sword--)
    {
      while (ptr < lim && *ptr != tab)
        ++ptr;
      if (ptr < lim)
        ++ptr;
    }
  }
  else
  {
    while (1)
      ;
  }

  if (ptr + schar <= lim)
    ptr += schar;

  return ptr;
}

int main(int argc, char *argv[]) {
  char *s = argv[1];
  char *lim = s + atoi(argv[2]);
  if (begfield(':', s, lim, 1, 1) != s + 2)
    abort ();
  exit (0);
}
