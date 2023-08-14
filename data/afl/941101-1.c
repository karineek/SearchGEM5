// Modification timestamp: 2023-08-14 13:41:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941101-1.c

#include <stdio.h>
#include <stdlib.h>

int f() {
  int var = atoi(argv[1]);

  if ((var/7) == 1)
    return var/7;
  return 0;
}

int main(int argc, char *argv[]) {
  if (f() != 1)
    abort();
  exit(0);
}
