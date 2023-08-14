// Modification timestamp: 2023-08-14 15:49:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70127.c

#include <stdio.h>
#include <stdlib.h>

struct S { int f; signed int g : 2; } a[1], c = {5, 1}, d;
short b;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  while (b++ <= 0)
    {
      struct S e = {1, 1};
      d = e = a[0] = c;
    }
  foo (a[0].g);
  return 0;
}

__attribute__((noinline, noclone)) void foo(int x) {
  if (x != 1)
    __builtin_abort ();
}
