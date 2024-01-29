// Modification timestamp: 2023-08-14 13:50:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980617-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(unsigned int *p) {
  if ((signed char)(*p & 0xFF) == atoi(argv[1]) || (signed char)(*p & 0xFF) == atoi(argv[2])) {
    return;
  } else {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[3]);
  foo(&i);
  exit(0);
}
