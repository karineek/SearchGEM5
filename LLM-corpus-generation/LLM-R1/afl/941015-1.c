// Modification timestamp: 2023-08-14 13:40:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941015-1.c

#include <stdio.h>
#include <stdlib.h>

int foo1(long long value) {
  register const long long constant = 0xc000000080000000LL;

  if (value < constant)
    return 1;
  else
    return 2;
}

int foo2(unsigned long long value) {
  register const unsigned long long constant = 0xc000000080000000LL;

  if (value < constant)
    return 1;
  else
    return 2;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned long long value = strtoull(argv[1], NULL, 16);
  int x, y;

  x = foo1(value);
  y = foo2(value);
  if (x != y || x != 1)
    abort ();
  exit (0);
}
