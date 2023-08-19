// Modification timestamp: 2023-08-14 13:09:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070724-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int main(int argc, char *argv[]) {
  static unsigned char magic[] = {argv[1][0]};
  static unsigned char value = argv[2][0];

  if (value != magic[0])
    abort();
  return 0;
}


Note: Since `magic` and `value` are static variables, their assignments are done before the execution of the `main` function. Therefore, the value of `argv` is accessed inside the declaration and initialization of `magic` and `value`.