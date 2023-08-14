// Modification timestamp: 2023-08-14 15:14:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46909-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

int foo(unsigned int x, int arg1, int arg2, int arg3, int arg4) {
  if (!((x == arg1) || (x == arg2)) || ((x == arg3) || (x == arg4))) {
    return 1;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  int arg3 = atoi(argv[3]);
  int arg4 = atoi(argv[4]);
  
  for (i = -10; i < 10; i++) {
    if (foo(i, arg1, arg2, arg3, arg4) != 1 - 2 * (i == arg1)) {
      abort();
    }
  }
  
  return 0;
}

