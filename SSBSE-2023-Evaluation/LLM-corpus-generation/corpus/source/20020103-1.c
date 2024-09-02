// Modification timestamp: 2023-08-14 12:07:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020103-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
extern void exit (int);

unsigned long foo (unsigned long a) {
  return a ^ 0x0000ffff;
}

unsigned long bar (unsigned long a) {
  return a ^ 0xffff0000;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  if (foo(atoi(argv[1])) != 0x0000ffff) {
    abort();
  }

  if (bar(atoi(argv[2])) != 0xffff0000) {
    abort();
  }

  exit(0);
}
