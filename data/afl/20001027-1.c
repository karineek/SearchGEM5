// Modification timestamp: 2023-08-14 11:53:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001027-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x;
  int *p = &x;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = 0;
  x = atoi(argv[1]);
  p[i] = atoi(argv[2]);

  if (x != 2)
    abort ();

  exit(0);
}
