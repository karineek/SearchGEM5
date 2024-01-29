// Modification timestamp: 2023-08-14 14:06:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bitfld-2.c

#include <stdio.h>
#include <stdlib.h>

struct A {
  unsigned short a : 5;
  unsigned short b : 5;
  unsigned short c : 6;
};

struct B {
  unsigned short a : 5;
  unsigned short b : 3;
  unsigned short c : 8;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  /* If short is not at least 16 bits wide, don't test anything.  */
  if ((unsigned short)atoi(argv[1]) != atoi(argv[1])) {
    exit(0);
  }

  if (sizeof(struct A) != sizeof(struct B)) {
    abort();
  }

  exit(0);
}

