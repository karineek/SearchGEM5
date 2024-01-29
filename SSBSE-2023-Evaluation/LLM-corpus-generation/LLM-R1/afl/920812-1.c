// Modification timestamp: 2023-08-14 13:29:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920812-1.c

#include <stdio.h>
#include <stdlib.h>

typedef int t;

int f(t y) {
  switch (y) {
    case 1:
      return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if (f((t)atoi(argv[1])) != 1) {
    abort();
  }
  exit(0);
}
