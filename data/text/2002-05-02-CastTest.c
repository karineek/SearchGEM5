c
// Modification timestamp: 2023-08-04 16:59:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/2002-05-02-CastTest.c

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

typedef unsigned char uint8;
typedef signed char int8;

int main(int argc, char** argv) {
    char c1 = (argc >= 2) ? atoi(argv[1]) : 100;
    short s1 = (argc >= 3) ? atoi(argv[2]) : -769;

    unsigned char ubc0 = (unsigned char)c1;
    uint8 ubs0 = (uint8)s1;
    uint8 ubs1 = ubs0 + 1;

    int8 bs0 = (int8)ubs0;
    int8 bs1 = (int8)(ubs0 + 1U);

    unsigned char uc2 = (unsigned char)c1;
    unsigned short us2 = (unsigned short)s1;

    int ic3 = (int)c1;
    int is3 = (int)s1;
    int is4 = ((int)ubs0) + 1;
    int is5 = ((int)bs0) + 1;

    unsigned int uic4 = (unsigned int)c1;
    unsigned int uis4 = (unsigned int)s1;

    printf("ubc0 = '%c'\t   [0x%x]\n", ubc0, ubc0);
    printf("ubs0 = %u\t   [0x%x]\n", ubs0, ubs0);
    printf("ubs1 = %u\t   [0x%x]\n", ubs1, ubs1);
    printf("bs0  = %d\t   [0x%x]\n", bs0, bs0);
    printf("bs1  = %d\t   [0x%x]\n", bs1, bs1);
    printf("c1   = '%c'\t   [0x%x]\n", c1, c1);
    printf("s1   = %d\t   [0x%x]\n", s1, s1);
    printf("uc2  = '%c'\t   [0x%x]\n", uc2, uc2);
    printf("us2  = %u\t   [0x%x]\n", us2, us2);
    printf("ic3  = '%c'\t   [0x%x]\n", ic3, ic3);
    printf("is3  = %d\t   [0x%x]\n", is3, is3);
    printf("is4  = %d\t   [0x%x]\n", is4, is4);
    printf("is5  = %d\t   [0x%x]\n", is5, is5);
    printf("uic4 = '%c'\t   [0x%x]\n", uic4, uic4);
    printf("uis4 = %u  [0x%x]\n", uis4, uis4);

    return 0;
}
