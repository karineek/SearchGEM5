// Modification timestamp: 2023-08-14 13:41:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950511-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned long long xx;
  unsigned long long *x = (unsigned long long *) &xx;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  *x = atoi(argv[1]);
  *x = *x * *x;
  if (*x != 9)
    abort ();
  exit (0);
}
