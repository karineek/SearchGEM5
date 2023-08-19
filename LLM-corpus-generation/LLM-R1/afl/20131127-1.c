// Modification timestamp: 2023-08-14 13:21:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20131127-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

#pragma pack(1)

struct S0 {
  int f0;
  int f1;
  int f2;
  short f3;
};

short a = 1;

struct S0 b = { 1 }, c, d, e;

struct S0 fn1() { return c; }

void fn2 (void)
{
  b = fn1 ();
  a = 0;
  d = e;
}

int main (void)
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  fn2 ();
  if (x != 0)
    abort ();
  return 0;
}
