// Modification timestamp: 2023-08-14 15:27:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57130.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct S { int a, b, c, d; } s[2] = { { 6, 8, -8, -5 }, { 0, 2, -1, 2 } };

__attribute__((noinline, noclone)) void
foo (struct S r)
{
  static int cnt;
  if (memcmp(&r, &s[cnt++], sizeof r) != 0)
    abort();
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int cnt = atoi(argv[1]);

  struct S r = { 6, 8, -8, -5 };
  foo(r);
  r = (struct S) { 0, 2, -1, 2 };
  foo(r);

  return cnt;
}

//Note: The added `int cnt` variable in the `main` function is to demonstrate the usage of an additional argument.