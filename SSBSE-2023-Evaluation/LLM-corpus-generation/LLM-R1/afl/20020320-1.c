// Modification timestamp: 2023-08-14 12:11:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020320-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

struct large { int x, y[9]; };

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int fixed;

  int temp1 = atoi(argv[1]);
  int temp2 = atoi(argv[2]);
  fixed = temp1 - temp2;

  if (fixed != 1)
    abort();

  struct large temp3;
  temp3.x = atoi(argv[3]);
  struct large temp4;
  temp4.x = atoi(argv[4]);
  fixed = temp3.x - temp4.x;

  if (fixed != 1)
    abort();

  exit(0);
}

