// Modification timestamp: 2023-08-14 11:58:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010422-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned int foo(unsigned int x)
{
  if (x < 5)
    x = atoi(argv[1]);
  else
    x = atoi(argv[2]);
  return x;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  if (foo(atoi(argv[1])) != atoi(argv[2]))
    abort ();
  exit (0);
}
