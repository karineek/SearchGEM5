// Modification timestamp: 2023-08-14 12:51:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040208-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  long double x;

  x = strtold(argv[1], NULL);
  x *= strtold(argv[2], NULL);
  if (x != strtold(argv[3], NULL))
    abort ();
  exit (0);
}
