// Modification timestamp: 2023-08-14 14:43:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19005.c


#include <stdio.h>
#include <stdlib.h>

int v, s;

void bar(int a, int b) {
  unsigned char x = v;

  if (!s) {
    if (a != x || b != (unsigned char)(x + 1))
      abort();
  } else if (a != (unsigned char)(x + 1) || b != x)
    abort();
  s ^= 1;
}

int foo(int x) {
  unsigned char a = x, b = x + 1;

  bar(a, b);
  a ^= b;
  b ^= a;
  a ^= b;
  bar(a, b);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  for (v = atoi(argv[1]) - 10; v < 266; v++)
    foo(v);
  return 0;
}
