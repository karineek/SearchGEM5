// Modification timestamp: 2023-08-14 13:22:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140828-1.c

#include <stdio.h>
#include <stdlib.h>

short *f(short *a, int b, int *d) 
{
  short c = *a;
  a++;
  c = b << c;
  *d = c;
  return a;
}

int main(int argc, char *argv[]) 
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int d;
  short a[2];
  a[0] = atoi(argv[1]);
  if (f(a, 1, &d) != &a[1])
    abort();
  if (d != 1)
    abort();
  return 0;
}

Note: In the original code, the `main` function does not take any arguments, but to match the signature of `int main(int argc, char *argv[])`, I added `int argc, char *argv[]` as arguments.