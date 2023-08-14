// Modification timestamp: 2023-08-14 17:12:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-04-22-Switch.c

#include <stdio.h>

static int func(unsigned i) {
  int X = atoi(argv[1]);
  switch (i) {
  case atoi(argv[2]): printf("C\n"); /* fall through. */  X = atoi(argv[3]);
  case atoi(argv[4]):
  case atoi(argv[5]):
  case atoi(argv[6]): printf("A\n"); break;
  case atoi(argv[7]):
  case atoi(argv[8]): X = atoi(argv[9]);
  case atoi(argv[10]): printf("B\n"); break;
  default: printf("D\n"); X = atoi(argv[11]);
  }
  return X;
}


int main(int argc, char *argv[]) {
  if (argc != 12) {
    printf("Usage: %s <value> <value> <value> <value> <value> <value> <value> <value> <value> <value> <value> <value>\n", argv[0]);
    return 1;
  }

  unsigned i;
  for (i = 0; i < 10; ++i)
    func(i);
  return 0;
}

