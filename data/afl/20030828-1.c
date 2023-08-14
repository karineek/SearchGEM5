// Modification timestamp: 2023-08-14 12:48:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030828-1.c

#include <stdio.h>
#include <stdlib.h>

const int *p;

int bar(void) {
  return *p + 1;
}

int main(int argc, char *argv[]) {
  const int i = atoi(argv[1]);
  p = &i;
  if (bar() != 6)
    abort();
    
  return 0;
}
