// Modification timestamp: 2023-08-14 13:57:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991202-3.c

#include <stdio.h>
#include <stdlib.h>

unsigned int f(unsigned int a) {
  return a * 65536 / 8;
}

unsigned int g(unsigned int a) {
  return a * 65536;
}

unsigned int h(unsigned int a) {
  return a / 8;
}

int main(int argc, char *argv[]) {
  if (f(atoi(argv[1])) != h(g(atoi(argv[2]))))
    abort();
  exit(0);
}
