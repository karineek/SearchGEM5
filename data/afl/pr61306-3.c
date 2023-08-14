// Modification timestamp: 2023-08-14 15:39:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61306-3.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  short a = atoi(argv[1]);
  int b;
  char c;

  c = a;
  b = a | c;
  if (b != -1)
    __builtin_abort ();
  return 0;
}
