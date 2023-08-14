// Modification timestamp: 2023-08-14 13:24:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20190228-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a = atoi(argv[1]);

  a = ~(a && 1);
  if (a < -1)
    a = ~a;

  if (!a)
    __builtin_abort ();

  return 0;
}
