// Modification timestamp: 2023-08-14 13:42:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950706-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int n) {
  return (n > 0) - (n < 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  
  if (f(-1) != -1)
    abort();
  if (f(1) != 1)
    abort();
  if (f(0) != 0)
    abort();
  
  exit(0);
}
