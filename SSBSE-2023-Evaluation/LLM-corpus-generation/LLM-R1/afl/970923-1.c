// Modification timestamp: 2023-08-14 13:48:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/970923-1.c

#include <stdio.h>
#include <stdlib.h>

int ts(int a) {
  if (a < 1000 && a > 2000)
    return 1;
  else
    return 0;
}

int tu(unsigned int a) {
  if (a < 1000 && a > 2000)
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  if (ts(atoi(argv[1])) || tu(atoi(argv[2])))
    abort();
  exit(0);
}
