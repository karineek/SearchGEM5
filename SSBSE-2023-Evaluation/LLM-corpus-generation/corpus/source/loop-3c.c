// Modification timestamp: 2023-08-14 14:31:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-3c.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void * a[255];

void f(int m) {
  int i;
  int sh = 0x100;
  i = m;
  do {
    a[sh >>= 1] = ((unsigned)i << 3) + (char*)a;
    i += 4;
  } while (i < INT_MAX/2 + 1 + 4 * 4);
}

int main(int argc, char *argv[]) {
  a[0x10] = 0;
  a[0x08] = 0;
  
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int m = atoi(argv[1]);
  f(m);

  if (a[0x10] || a[0x08])
    abort();

  a[0x10] = 0;
  a[0x08] = 0;
  f(INT_MAX/2 + 1);

  if (!a[0x10] || a[0x08])
    abort();

  exit(0);
}
