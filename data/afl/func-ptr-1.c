// Modification timestamp: 2023-08-14 14:27:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/func-ptr-1.c

#include <stdio.h>
#include <stdlib.h>

static double f(float a);
static double (*fp)(float a);

static double f(float a) {
  return a;
}

int main(int argc, char *argv[]) {
  fp = f;
  if (fp((float)1) != 1.0)
    abort();
  exit(0);
}
