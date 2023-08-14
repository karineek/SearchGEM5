// Modification timestamp: 2023-08-14 16:52:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-1.c

#include <stdio.h>
#include <stdlib.h>

struct S
{
  char f1;
  int f2[2];
};

int main(int argc, char *argv[]) {
  struct S object;
  object.f1 = argv[1][0];
  object.f2[0] = atoi(argv[2]);
  object.f2[1] = atoi(argv[3]);

  if (object.f1 != 'X' || object.f2[0] != 8 || object.f2[1] != 9)
    abort ();
  exit (0);
}
