// Modification timestamp: 2023-08-14 13:26:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-1.c

#include <stdio.h>
#include <stdlib.h>

int s[2];
int x() {
  if (!s[0]) {
    s[1 + s[1]] = s[1];
    return 1;
  }
}

int main(int argc, char *argv[]) {
  s[0] = s[1] = atoi(argv[1]);
  if (x(0) != 1)
    abort();
  exit(0);
}
