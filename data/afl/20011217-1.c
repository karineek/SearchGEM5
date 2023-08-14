// Modification timestamp: 2023-08-14 12:07:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011217-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double x = atof(argv[1]);
  double y = atof(argv[2]);

  if ((y > x--) != 1)
    abort ();

  exit(0);
}
