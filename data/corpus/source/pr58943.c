// Modification timestamp: 2023-08-14 15:35:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58943.c

#include <stdio.h>
#include <stdlib.h>

unsigned int x[1] = { 2 };

unsigned int foo(unsigned int arg1) {
  arg1 |= 128;
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int arg1 = atoi(argv[1]);
  x[0] |= foo(arg1);
  if (x[0] != 131)
    __builtin_abort();
  
  return 0;
}
