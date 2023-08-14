// Modification timestamp: 2023-08-14 12:49:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030920-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int hicount = 0;
  unsigned char *c;
  char *str = argv[1];
  for (c = (unsigned char *)str; *c; c++) {
    if (!(((unsigned int)(*c)) < 0x80))
      hicount++;
  }
  if (hicount != 1)
    abort();
  return 0;
}
