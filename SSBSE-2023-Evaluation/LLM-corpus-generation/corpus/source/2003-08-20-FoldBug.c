// Modification timestamp: 2023-08-14 17:16:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-08-20-FoldBug.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int foo (int x) {
  if ((int) (x & 0x80ffffff) != (int) (0x8000fffe))
    abort ();

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  foo(x);
  printf("All ok\n");
  return 0;
}
