// Modification timestamp: 2023-08-14 17:15:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-07-10-SignConversions.c

#include <stdio.h>

unsigned char getUC(char* a1) { return *a1; }

signed   char getSC(char* a2) { return *a2; }

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  signed   char  SC80 = getSC(argv[1]);
  unsigned char  UC80 = getUC(argv[2]);

  /* source is smaller than dest: both decide */
  unsigned short us  = (unsigned short) SC80;     /* sign-ext then zero-ext */
  unsigned short us2 = (unsigned short) UC80;     /* zero-ext only: NOP! */
           short  s  = (         short) SC80;     /* sign-ext */
           short  s2 = (         short) UC80;     /* zero-extend only : NOP! */
  printf("%d %d --> unsigned: us = %d, us2 = %d\n", SC80, UC80, us, us2);
  printf("%d %d -->   signed:  s = %d,  s2 = %d\n", SC80, UC80,  s,  s2);

  /* source is same size or larger than dest: dest decides */
  unsigned char  uc  = (unsigned char ) SC80;     /* zero-ext */
  unsigned char  uc2 = (unsigned char ) UC80;     /* NOP */
  signed   char  sc  = (signed   char ) SC80;     /* NOP */
  signed   char  sc2 = (signed   char ) UC80;     /* sign-extend */
  printf("%d %d --> unsigned: uc = %d, uc2 = %d\n", SC80, UC80, uc, uc2);
  printf("%d %d -->   signed: sc = %d, sc2 = %d\n", SC80, UC80, sc, sc2);
  return 0;
}
