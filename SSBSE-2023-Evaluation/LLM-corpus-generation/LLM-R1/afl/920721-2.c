// Modification timestamp: 2023-08-14 13:28:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920721-2.c

#include <stdio.h>
#include <stdlib.h>

void f() {}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  double x[n];
  f();
  exit(0);
}

Note: The code assumes that the value of `n` is passed as a command-line argument.