//c
// Modification timestamp: 2023-08-10 16:32:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000503-1.c
#include <string.h>
#include <stdio.h>

#include <stdlib.h>

unsigned long sub (int a)
{
  return ((0 > a - 2) ? 0 : a - 2) * sizeof (long);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  if (sub (a) != 0)
    abort ();

  exit (0);
}
