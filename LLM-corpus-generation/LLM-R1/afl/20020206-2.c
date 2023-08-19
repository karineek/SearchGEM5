// Modification timestamp: 2023-08-14 12:09:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020206-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct { unsigned short a; } A;

extern void abort (void);
extern void exit (int);

void foo (unsigned int x)
{
  if (x != 0x800 && x != 0x810)
    abort ();
}

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < 2; ++i)
    foo(((A) { ((!(i >> 4) ? 8 : 64 + (i >> 4)) << 8) + (i << 4) } ).a);
  exit(0);
}
