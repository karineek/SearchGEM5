// Modification timestamp: 2023-08-14 15:51:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr7284-1.c

#include <stdio.h>
#include <stdlib.h>

void abort (void);
void exit (int);

int f (int n)
{
  return (n << 24) / (1 << 23);
}

volatile int x;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);

  if (f(x) != -256)
    abort ();
  exit (0);
}
