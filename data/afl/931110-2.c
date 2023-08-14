// Modification timestamp: 2023-08-14 13:39:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931110-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  static int a[] = {3, 4};
  register int *b;
  int c;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  b = a;
  c = *b++ % atoi(argv[1]);
  if (c != 3)
    abort ();
  exit (0);
}
