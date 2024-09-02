// Modification timestamp: 2023-08-14 13:51:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980929-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int i)
{
  if (i != 1000)
    abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  int i;

  f(n);
  for(i=0; i<1; ++i) {
    f(n);
    n=666;
    &n;
  }

  exit (0);
}
