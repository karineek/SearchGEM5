// Modification timestamp: 2023-08-14 13:40:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941014-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int a, int b) { }

int main(int argc, char *argv[]) {
  unsigned long addr1;
  unsigned long addr2;

  addr1 = (unsigned long) &f;
  addr1 += 5;
  addr2 = 5 + (unsigned long) &f;

  if (addr1 != addr2)
    abort ();
  
  exit (0);
}
