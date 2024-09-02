// Modification timestamp: 2023-08-14 12:45:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030404-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int i = atoi(argv[1]);
  int j, k;
  
  k = 0;
  while (k < 10) {
    k++;
    if (j > i)
      j = 5;
    else
      j = 3;
  }

  if (k != 10)
    abort ();

  return 0;
}
