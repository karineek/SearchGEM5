// Modification timestamp: 2023-08-14 13:55:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990527-1.c

#include <stdio.h>
#include <stdlib.h>

int sum;

void g(int i) {
  sum += i;
}

void f(int j) {
  int i;

  for (i = 0; i < 9; i++) {
    j++;
    g(j);
    j = 9;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int j = atoi(argv[1]);
  f(j);
  if (sum != 81)
    abort ();
  exit(0);
}
