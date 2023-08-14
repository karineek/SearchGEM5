// Modification timestamp: 2023-08-14 15:42:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65053-1.c

#include <stdio.h>
#include <stdlib.h>

int i;

__attribute__ ((noinline, noclone))
unsigned int foo (void)
{
  return 0;
}

int main(int argc, char *argv[]) {
  unsigned int u = -1;
  if (u == -1)
  {
    if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
    }

    unsigned int n = foo ();
    if (n > 0)
      u = n - 1;
  }

  while (u != -1)
  {
    asm ("" : "+g" (u));
    u = -1;
    i = 1;
  }

  if (i)
    __builtin_abort ();
  return 0;
}
