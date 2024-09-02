// Modification timestamp: 2023-08-14 12:45:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030401-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

int bar ()
{
  return 1;
}

void foo (int x)
{
  int argc = 2;
  char *argv[2] = {"program_name", "1"};

  unsigned char error = 0;

  if (! (error = ((x == 0) || bar ())))
    bar ();
  if (! error)
    abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo(atoi(argv[1]));
  return 0;
}
