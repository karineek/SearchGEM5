// Modification timestamp: 2023-08-14 15:48:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69403.c

#include <stdio.h>
#include <stdlib.h>

int a, b, c;

__attribute__ ((__noinline__)) int
fn1(int a, int b, int c)
{
  if ((b | (a != (a & c))) == 1)
    __builtin_abort ();
  return 0;
}

int
main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <a> <b> <c>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  c = atoi(argv[3]);
  return fn1(a, b, c);
}
