c
// Modification timestamp: 2023-08-10 14:45:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2003-04-22-Switch.c

#include <stdio.h>
#include <stdlib.h>

static int func(unsigned i, int X) {
  switch (i) {
  case 8: printf("C\n"); /* fall through. */  X = 6;
  case 0:
  case 3:
  case 2: printf("A\n"); break;
  case 1:
  case 7: X = 7;
  case 9: printf("B\n"); break;
  default: printf("D\n"); X = 1;
  }
  return X;
}


int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  unsigned i = atoi(argv[1]);

  int X = 4;
  for (i = 0; i < 10; ++i)
    X = func(i, X);

  return 0;
}
