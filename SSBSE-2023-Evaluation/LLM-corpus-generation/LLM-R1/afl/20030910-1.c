// Modification timestamp: 2023-08-14 12:48:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030910-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  __complex double dc;
  double *dp = &(__real__ dc);
  *dp = atof(argv[1]);
  if ((__real__ dc) != atof(argv[1])) abort();
  exit(0);
}

Note: In the original code, the value 3.14 was assigned to `*dp` and then compared with `__real dc`, which could potentially be a float precision mismatch issue. To avoid this, I replaced the constant `3.14` with `atof(argv[1])` to take the value from the command-line argument.