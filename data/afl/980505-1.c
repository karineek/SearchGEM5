// Modification timestamp: 2023-08-14 13:48:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980505-1.c

#include <stdio.h>
#include <stdlib.h>

static int f(int) __attribute__((const));

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int f1, f2, x;
  x = atoi(argv[1]);
  f1 = f(x);
  x = atoi(argv[2]);
  f2 = f(x);
  if (f1 != atoi(argv[3]) || f2 != atoi(argv[4])) {
    abort();
  }
  exit(0);
}

static int f(int x) {
  return x;
}


Note: The converted code assumes that the command line arguments are provided in the correct order: `./a.out <value> <value> <expected_f1> <expected_f2>`.