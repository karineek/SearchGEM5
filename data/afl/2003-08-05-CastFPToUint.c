
// Modification timestamp: 2023-08-10 15:00:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/252fff6f1f88bcab6126c7f1b9f696c7d8fde9b1/MultiSource/Benchmarks/ASCI_Purple/SMG2000/2003-08-05-CastFPToUint.c

#include <stdlib.h>
#include <stdio.h>

static double getDC(), getDS(), getDI();

int main(int argc, char **argv) {
    double DC = getDC();
    double DS = getDS();
    double DI = getDI();
    unsigned char uc = (unsigned char)atoi(argv[1]);
    unsigned short us = (unsigned short)atoi(argv[2]);
    unsigned int ui = (unsigned int)atoi(argv[3]);
    printf("DC = %lf, DS = %lf, DI = %lf\n", DC, DS, DI);
    printf("uc = %u, us = %u, ui = %u\n", uc, us, ui);
    return 0;
}

static double getDC() { return (double)((1L << 8) - 16L ); }
static double getDS() { return (double)((1LL << 16) - 16L ); }
static double getDI() { return (double)((1LL << 32) - 16LL); }
