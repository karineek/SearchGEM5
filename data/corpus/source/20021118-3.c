// Modification timestamp: 2023-08-14 12:38:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021118-3.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

int foo(int x) {
  if (x == atoi(argv[1]) || -x - 100 >= 0)
    abort();
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  foo(atoi(argv[1]));
  foo(atoi(argv[2]));
  exit(0);
}
