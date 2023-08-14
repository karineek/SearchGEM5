// Modification timestamp: 2023-08-14 13:27:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920603-1.c

#include <stdio.h>
#include <stdlib.h>

void f(unsigned got) {
  if (got != 0xffff)
    abort();
}

int main(int argc, char *argv[]) {
  signed char c = -1;
  unsigned u = (unsigned short)c;
  f(u);
  exit(0);
}
