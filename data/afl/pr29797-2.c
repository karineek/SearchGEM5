// Modification timestamp: 2023-08-14 14:52:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29797-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

unsigned long bar(void) { return 32768; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long nStyle = atoi(argv[1]);
  if (nStyle & 32768)
    nStyle |= 65536;
  if (nStyle != (32768 | 65536))
    abort ();
  return 0;
}
