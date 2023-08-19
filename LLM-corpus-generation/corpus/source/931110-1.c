// Modification timestamp: 2023-08-14 13:39:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931110-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short f:3, g:3, h:10;
} small;

struct {
  int i;
  small s[10];
} x;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < 10; i++) {
    x.s[i].f = atoi(argv[i + 1]);
  }

  exit(0);
}

//Note: The program expects 10 command line arguments (1 for the program name and 9 for `x.s[i].f`).