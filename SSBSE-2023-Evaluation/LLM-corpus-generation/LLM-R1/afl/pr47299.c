// Modification timestamp: 2023-08-14 15:15:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47299.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

__attribute__ ((noinline, noclone)) unsigned short
foo (unsigned char x)
{
  return x * 255;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char x = atoi(argv[1]);
  if (foo(x) != 0x3fc0)
    abort ();
  return 0;
}
