// Modification timestamp: 2023-08-14 13:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-1.c

#include <stdio.h>
#include <stdlib.h>

int val;

int *ptr = &val;
float *ptr2 = &val;

__attribute__((optimize ("-fno-strict-aliasing")))
void typepun() {
  *ptr2 = 0;
}

int main() {
  *ptr = 1;
  typepun();
  if (*ptr) {
    abort();
  }
  return 0;
}


Note: I have added the missing return type `int` to the `main()` function.