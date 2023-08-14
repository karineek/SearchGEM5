// Modification timestamp: 2023-08-14 14:49:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr23941.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  double d = atof(argv[1]) / 2.0;

  double x = atof(argv[2]) / 2.0;
  
  if (x != d)
    abort();

  return 0;
}

Note that in this case, the program requires two command line arguments for `d` and `x` respectively.