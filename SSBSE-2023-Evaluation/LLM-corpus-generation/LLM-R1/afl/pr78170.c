// Modification timestamp: 2023-08-14 15:52:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78170.c

#include <stdio.h>
#include <stdlib.h>

int a, b, d;

struct S0
{
  int f0;
  int f1;
  int f2;
  int f3;
  int f4;
  int f5:15;
  int f6:17;
  int f7:2;
  int f8:30;
} c;

void fn1 (int a, int b)
{
  d = b = 1;
  for (; b; b = a)
    {
      struct S0 e = { 0, 0, 0, 0, 0, 0, 1, 0, 1 };
      c = e;
      c.f6 = -1;
    }
}

int main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <a_value> <b_value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  fn1(a, b);

  if (c.f7 != 0)
    __builtin_abort ();
  return 0;
}
