// Modification timestamp: 2023-08-14 13:30:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920909-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int a) {
  switch(a) {
    case 0x402:
      return a + 1;
    case 0x403:
      return a + 2;
    case 0x404:
      return a + 3;
    case 0x405:
      return a + 4;
    case 0x406:
      return 1;
    case 0x407:
      return 4;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (f(atoi(argv[1])))
    abort();
  exit(0);
}
