// Modification timestamp: 2023-08-14 11:57:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010209-1.c

#include <stdio.h>
#include <stdlib.h>

int b;
int foo (int b)
{
  int x[b];
  int bar (int t[b])
  {
    int i;
    for (i = 0; i < b; i++)
      t[i] = i + (i > 0 ? t[i-1] : 0);
    return t[b-1];
  }
  return bar (x);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  b = atoi(argv[1]);
  if (foo (b) != 15)
    abort ();
  exit (0);
}
