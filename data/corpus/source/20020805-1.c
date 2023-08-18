// Modification timestamp: 2023-08-14 12:35:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020805-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
extern void exit (int);

void check(unsigned int m) {
  if (m != (unsigned int)-1)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int n = atoi(argv[1]);
  unsigned int m;
  m = (1 | (2 - n)) | (-n);
  check(m);
  exit(0);
}

