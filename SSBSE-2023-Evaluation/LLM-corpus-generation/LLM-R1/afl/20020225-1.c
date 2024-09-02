// Modification timestamp: 2023-08-14 12:10:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020225-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned long foo (unsigned long base, unsigned int val)
{
  return base + (val & 0x80000001);
}

int main(int argc, char *argv[]) {
  unsigned long base = strtoul(argv[1], NULL, 0);
  unsigned int val = strtoul(argv[2], NULL, 0);
  
  if (foo(base, val) != 0L)
    abort ();

  exit (0);
}
