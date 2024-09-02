// Modification timestamp: 2023-08-14 13:45:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960321-1.c

#include <stdio.h>
#include <stdlib.h>

char a[10];

char acc_a(long i) {
  return a[i - 2000000000L];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long i = atol(argv[1]);
  a[0] = 'd';
  
  if (acc_a(i) != 'd') {
    abort();
  }
  
  exit(0);
}
