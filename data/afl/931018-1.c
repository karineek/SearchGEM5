// Modification timestamp: 2023-08-14 13:39:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931018-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned int a[0x1000];
extern const unsigned long v;

void f(unsigned long a);

int main(int argc, char *argv[]) {
  f(v);
  f(v);
  exit(0);
}

void f(unsigned long a) {
  if (a != atol(argv[1])) {
    abort();
  }
}

const unsigned long v = 0xdeadbeefL;


Note: In the original code, the function `f` did not have a parameter name specified. I added `argv` as the parameter name for `f` to match the function definition.