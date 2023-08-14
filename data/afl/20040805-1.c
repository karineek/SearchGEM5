// Modification timestamp: 2023-08-14 12:58:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040805-1.c

#include <stdio.h>
#include <stdlib.h>

#define __INT_MAX__ 32768

int a[2] = { 2, 3 };

static int __attribute__((noinline))
bar (int x, void *b)
{
  a[0]++;
  return x;
}

static int __attribute__((noinline))
foo (int x)
{
  char buf[0x10000];
  int y = a[0];
  a[1] = y;
  x = bar (x, buf);
  y = bar (y, buf);
  return x + y;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  if (foo(x) != 102)
    abort();
  exit(0);
}
