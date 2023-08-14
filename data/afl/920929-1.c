// Modification timestamp: 2023-08-14 13:30:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920929-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int n) {
  int i;
  double v[n];
  for(i = 0; i < n; i++)
    v[i] = 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  f(n);
  return 0;
}
