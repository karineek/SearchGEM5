// Modification timestamp: 2023-08-14 11:54:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001121-1.c

#include <stdio.h>
#include <stdlib.h>

double d;

__inline__ double foo (void)
{
  return d;
}

__inline__ int bar (void)
{
  foo();
  return 0;
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  d = atof(argv[1]);
  
  if (bar ())
    abort ();
  exit (0);
}
