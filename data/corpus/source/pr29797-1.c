// Modification timestamp: 2023-08-14 14:52:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29797-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

unsigned int bar(void) { return atoi(argv[1]); }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int nStyle = bar();
  if (nStyle & 32768)
    nStyle |= 65536;
  if (nStyle != (32768 | 65536))
    abort();
  return 0;
}
