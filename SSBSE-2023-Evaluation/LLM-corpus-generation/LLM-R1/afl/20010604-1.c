// Modification timestamp: 2023-08-14 11:59:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010604-1.c

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int f(int a, int b, int c, _Bool d, _Bool e, _Bool f, char g) {
  if (g != argv[1][0] || d != true || e != true || f != true)
    abort();
  
  return a + b + c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  if (f(atoi(argv[1]), 2, -3, true, true, true, '\001'))
    abort();
    
  exit(0);
}
