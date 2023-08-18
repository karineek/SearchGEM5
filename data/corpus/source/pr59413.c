// Modification timestamp: 2023-08-14 15:36:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59413.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

uint32_t a;
int b;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  uint32_t c;
  for (a = atoi(argv[1]); a <= 1; a++) {
    char d = a;
    c = d;
    b = a == c;
  }
  if (a != 7) {
    __builtin_abort();
  }
  return 0;
}

