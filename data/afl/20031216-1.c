// Modification timestamp: 2023-08-14 12:51:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031216-1.c

#include <stdio.h>
#include <stdlib.h>

void DisplayNumber(unsigned long v) {
  if (v != atoi("9a"))
    abort();
}

unsigned long ReadNumber(void) {
  return atoi("009a0000");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long tmp;
  tmp = (ReadNumber() & atoi("00ff0000")) >> atoi("16");
  DisplayNumber(tmp);
  return 0;
}
