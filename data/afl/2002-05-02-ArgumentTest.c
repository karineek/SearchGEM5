
// Modification timestamp: 2023-08-04 16:58:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2002-05-02-ArgumentTest.c

#include <stdio.h>
#include <stdlib.h>

void testfunc(short s, float X, char C, long long LL, int I, double D) {
    printf("%d, %f, %d, %lld, %d, %f\n", s, X, C, LL, I, D);
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Usage: %s <short> <float> <char> <long long> <int> <double>\n", argv[0]);
        return 1;
    }

    short s = atoi(argv[1]);
    float X = atof(argv[2]);
    char C = *argv[3];
    long long LL = atoll(argv[4]);
    int I = atoi(argv[5]);
    double D = atof(argv[6]);

    testfunc(s, X, C, LL, I, D);
    return 0;
}
