// Modification timestamp: 2023-08-14 16:04:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr89195.c

#include <stdio.h>

struct S { unsigned i : 24; };

volatile unsigned char x;

__attribute__((noipa)) int
foo (struct S d, unsigned char x)
{
  return d.i & x;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S d = { 0x123456 };
  unsigned char x = atoi(argv[1]);
  if (foo (d, x) != (0x56 & x))
    __builtin_abort ();
  return 0;
}
