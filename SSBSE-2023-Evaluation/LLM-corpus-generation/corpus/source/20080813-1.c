// Modification timestamp: 2023-08-14 13:15:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080813-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

void foo(unsigned short x) {
  signed char y = -1;
  if (x == y)
    abort();
}

void bar(unsigned short x) {
  unsigned char y = -1;
  if (x == y)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);

  if (sizeof(int) == sizeof(short))
    return 0;
  foo(value);
  if (sizeof(short) > 1)
    bar(value);
  return 0;
}
