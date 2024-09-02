// Modification timestamp: 2023-08-14 15:37:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60017.c

#include <stdio.h>
#include <stdlib.h>

struct S0
{
  short m0;
  short m1;
};

struct S1
{
  unsigned m0:1;
  char m1[2][2];
  struct S0 m2[2];
};

struct S1 x = { 1, {{2, 3}, {4, 5}}, {{6, 7}, {8, 9}} };

struct S1 func (void)
{
  return x;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  struct S1 ret = func();

  if (ret.m2[1].m1 != 9)
    abort();

  return 0;
}

