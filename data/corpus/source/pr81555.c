// Modification timestamp: 2023-08-14 15:56:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81555.c

#include <stdio.h>
#include <stdlib.h>

unsigned int a, d, e;
_Bool b, f;
unsigned char g;

void foo(unsigned int a, _Bool b, unsigned int d, _Bool c, unsigned int e, unsigned char g) {
  if (c)
    f = 0;
  if (e & c & (unsigned char)d & c)
    g = 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int a = atoi(argv[1]);
  unsigned int d = atoi(argv[2]);
  unsigned int e = atoi(argv[3]);
  _Bool b = atoi(argv[4]);
  _Bool f = atoi(argv[5]);
  unsigned char g = atoi(argv[6]);

  foo(a, b, d, b != 0, e, g);

  if (f || g != 1)
    __builtin_abort();

  return 0;
}
