// Modification timestamp: 2023-08-14 15:52:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78436.c

#include <stdio.h>
#include <stdlib.h>

struct S
{
  long int a : 24;
  signed char b : 8;
} s;

__attribute__((noinline, noclone)) void foo(long int a, signed char b)
{
  s.b = b;
  s.a = a;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  long int a = atol(argv[1]);
  signed char b = atoi(argv[2]);

  foo(a, b);

  if (s.b != 0)
    abort();

  return 0;
}
