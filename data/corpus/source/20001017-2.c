// Modification timestamp: 2023-08-14 11:52:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001017-2.c

#include <stdio.h>
#include <stdlib.h>

void fn_4parms(unsigned char a, long *b, long *c, unsigned int *d) {
  if (*b != 1 || *c != 2 || *d != 3)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <a> <b> <c> <d>\n", argv[0]);
    return 1;
  }

  unsigned char a = atoi(argv[1]);
  unsigned long b = atoi(argv[2]);
  unsigned long c = atoi(argv[3]);
  unsigned int d = atoi(argv[4]);

  fn_4parms(a, &b, &c, &d);
  return 0;
}
