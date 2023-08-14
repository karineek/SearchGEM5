// Modification timestamp: 2023-08-14 12:19:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020611-1.c

#include <stdio.h>
#include <stdlib.h>

int p;
int k;
unsigned int n;

void x(unsigned int n_arg)
{
  unsigned int h;

  h = n_arg <= 30;
  if (h)
    p = 1;
  else
    p = 0;

  if (h)
    k = 1;
  else
    k = 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int n = atoi(argv[1]);
  x(n);
  if (p != 1 || k != 1)
    abort ();
  exit (0);
}
