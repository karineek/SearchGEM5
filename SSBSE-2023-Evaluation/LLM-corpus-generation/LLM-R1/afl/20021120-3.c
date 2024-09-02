// Modification timestamp: 2023-08-14 12:38:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021120-3.c

#include <stdio.h>
#include <stdlib.h>

unsigned int foo (char *c, unsigned int x, unsigned int y)
{
  register unsigned int z LOC;

  sprintf (c, "%d", x / y);
  z = x + 1;
  return z / (y + 1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char c[16];
  unsigned int x = atoi(argv[1]);
  unsigned int y = 4;
  
  if (foo(c, ~1U, y) != (~0U / 5))
    abort ();
    
  exit (0);
}
