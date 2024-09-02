// Modification timestamp: 2023-08-14 13:54:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990413-2.c

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
  double x;

  x = -0.0;
  x = asin(x);

  if (x != 0.0) /* actually -0.0, but 0.0 == -0.0 */
    abort ();
  return 0;
}
