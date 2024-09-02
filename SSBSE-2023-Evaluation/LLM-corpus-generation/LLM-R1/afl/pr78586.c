// Modification timestamp: 2023-08-14 15:52:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78586.c

#include <stdio.h>
#include <stdlib.h>

void foo(unsigned long x) {
  char a[30];
  unsigned long b = __builtin_sprintf(a, "%lu", x);
  if (b != 4)
    __builtin_abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned long x = atol(argv[1]);
  foo(x);
  return 0;
}
