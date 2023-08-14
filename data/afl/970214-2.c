// Modification timestamp: 2023-08-14 13:48:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/970214-2.c

#include <stdio.h>
#include <stdlib.h>

#define m(L) (L'1' + (L))

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  exit(m(atoi(argv[1])) != L'1');
}

