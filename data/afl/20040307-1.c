// Modification timestamp: 2023-08-14 12:51:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040307-1.c

#include <stdio.h>
#include <stdlib.h>

int main() {
  int b = 0;

  struct {
    unsigned int bit0:1;
    unsigned int bit1:1;
    unsigned int bit2:1;
    unsigned int bit3:1;
    unsigned int bit4:1;
    unsigned int bit5:1;
    unsigned int bit6:1;
    unsigned int bit7:1;
  } sdata = {0x01};

  while ( sdata.bit0-- > 0 ) {
    b++ ;
    if ( b > 100 ) break;
  }

  if (b != atoi(argv[1]))
    abort ();
  return 0;
}
