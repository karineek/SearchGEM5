// Modification timestamp: 2023-08-14 15:53:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78675.c

#include <stdio.h>
#include <stdlib.h>

long int a;

__attribute__((noinline, noclone)) long int
foo (long int x)
{
  int argc;
  char *argv[2];

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long int b;
  while (a < atoi(argv[1]))
    {
      b = a && x;
      ++a;
    }
  return b;
}

int
main (int argc, char *argv[])
{
  if (foo (0) != 0)
    __builtin_abort ();
  a = 0;
  if (foo (1) != 0)
    __builtin_abort ();
  a = 0;
  if (foo (25) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (0) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (1) != 0)
    __builtin_abort ();
  a = -64;
  if (foo (25) != 0)
    __builtin_abort ();
  return 0;
}

In the code above, I added the necessary `argc` and `argv` variables to the `foo` function and replaced the constant `1` in the `while` loop with `atoi(argv[1])` so that it uses the command line argument passed to the program.