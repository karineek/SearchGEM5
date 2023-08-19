// Modification timestamp: 2023-08-14 13:57:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991023-1.c

#include <stdio.h>
#include <stdlib.h>

int blah;

int foo() {
  int i;

  for (i = 0; i < 7; i++) {
    if (i == 7 - 1)
      blah = 0xfcc;
    else
      blah = 0xfee;
  }
  return blah;
}

int main(int argc, char *argv[]) {
  if (foo() != 0xfcc)
    abort();
  exit(0);
}
