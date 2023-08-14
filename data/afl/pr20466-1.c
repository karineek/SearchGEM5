// Modification timestamp: 2023-08-14 14:44:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr20466-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int **, int *, int *, int **, int **) __attribute__((__noinline__));

int f(int **ipp, int *i1p, int *i2p, int **i3, int **i4) {
  **ipp = *i1p;
  *ipp = i2p;
  *i3 = *i4;
  **ipp = 99;
  return 3;
}

extern void exit(int);
extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int i1 = 66;
  int i2 = 1;
  int i3 = -1;
  int i4 = 55;
  int *ip = &i;
  int *i3p = &i3;
  int *i4p = &i4;

  f(&ip, &i1, &i2, &i3p, &i4p);
  if (i != 66 || ip != &i2 || i2 != 99 || i3 != -1 || i3p != i4p || i4 != 55)
    abort();
  exit(0);
}
