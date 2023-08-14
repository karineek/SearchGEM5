// Modification timestamp: 2023-08-14 15:18:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49281.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__((noinline, noclone)) int
foo(int x)
{
  return (x << 2) | 4;
}

__attribute__((noinline, noclone)) int
bar(int x)
{
  return (x << 2) | 3;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);

  if (foo(arg) != 172 || foo(1) != 4 || foo(2) != 12)
    abort();
  if (bar(arg) != 175 || bar(1) != 7 || bar(2) != 11)
    abort();

  return 0;
}
