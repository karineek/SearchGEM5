// Modification timestamp: 2023-08-14 14:57:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35390.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

unsigned int foo(int n) {
  return ~((unsigned int)~n);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int arg = atoi(argv[1]);

  if (foo(arg) != 0)
    abort();
  
  return 0;
}
