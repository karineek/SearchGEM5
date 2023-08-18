// Modification timestamp: 2023-08-14 17:15:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-08-05-CastFPToUint.c

#include <stdlib.h>
#include <stdio.h>

static double getDC(int argc, char** argv), getDS(int argc, char** argv), getDI(int argc, char** argv);

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double DC = getDC(argc, argv);
  double DS = getDS(argc, argv);
  double DI = getDI(argc, argv);
  unsigned char  uc = (unsigned char ) DC;
  unsigned short us = (unsigned short) DS;
  unsigned int   ui = (unsigned int  ) DI;
  printf("DC = %lf, DS = %lf, DI = %lf\n", DC, DS, DI);
  printf("uc = %u, us = %u, ui = %u\n", uc, us, ui);
  return 0;
}

static double getDC(int argc, char** argv) { return (double) ((1L  <<  8) - 16L ); }
static double getDS(int argc, char** argv) { return (double) ((1LL << 16) - 16L ); }
static double getDI(int argc, char** argv) { return (double) ((1LL << 32) - 16LL); }
