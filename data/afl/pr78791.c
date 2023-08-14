// Modification timestamp: 2023-08-14 15:53:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78791.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((used, noinline, noclone)) unsigned long long
foo (unsigned long long x, unsigned long long y, unsigned long long z)
{
  unsigned long long a = x / y;
  unsigned long long b = x % y;
  a |= z;
  b ^= z;
  return a + b;
}

int
main (int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <x> <y> <z>\n", argv[0]);
    return 1;
  }

  unsigned long long x = strtoull(argv[1], NULL, 10);
  unsigned long long y = strtoull(argv[2], NULL, 10);
  unsigned long long z = strtoull(argv[3], NULL, 10);

  if (foo (x, y, z) != 10 || foo (28, 3, 2) != 14)
    __builtin_abort ();
  return 0;
}
