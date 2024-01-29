// Modification timestamp: 2023-08-14 13:29:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920728-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {int dims[0]; } *A;

void f(unsigned long obj) {
  unsigned char y = obj >> 24;
  y &= ~4;

  if ((y == 0) || (y != 251)) {
    abort();
  }

  if (((int)obj & 7) != 7) {
    return;
  }

  // REST_OF_CODE_JUST_HERE_TO_TRIGGER_THE_BUG:

  {
    unsigned char t = obj >> 24;
    if (!(t == 0) && (t <= 0x03)) {
      return 0;
    }
    return ((A)(obj & 0x00FFFFFFL))->dims[1];
  }
}

long g() {
  return 0xff000000L;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long value = strtoul(argv[1], NULL, 0);
  f(value);
  exit(0);
}
