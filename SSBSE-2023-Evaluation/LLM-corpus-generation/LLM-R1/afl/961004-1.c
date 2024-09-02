// Modification timestamp: 2023-08-14 13:47:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961004-1.c

#include <stdio.h>
#include <stdlib.h>

int k = 0;

int main(int argc, char *argv[]) {
  int i;
  int j;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);

  for (i = 0; i < arg1; i++) {
    if (k) {
      if (j != 2)
        abort();
    } else {
      j = 2;
      k++;
    }
  }

  exit(0);
}
