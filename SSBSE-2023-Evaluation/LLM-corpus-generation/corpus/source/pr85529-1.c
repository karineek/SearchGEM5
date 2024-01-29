// Modification timestamp: 2023-08-14 16:01:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85529-1.c

#include <stdio.h>
#include <stdlib.h>

struct S { int a; };

int b, c = 1, d, e, f;
static int g;
volatile struct S s;

signed char foo(signed char i, int j) {
  return i < 0 ? i : i << j;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char k = atoi(argv[1]);
  if (!d)
    goto L;
  k = e || f;
L:
  for (; b < 1; b++)
    s.a != (k < foo(k, 2) && (c = k = g));
  if (c != 1)
    __builtin_abort();
  return 0;
}
