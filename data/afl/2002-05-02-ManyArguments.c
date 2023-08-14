
// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2002-05-02-ManyArguments.c

#include <stdio.h>
#include <stdlib.h>

void printfn(int a, short b, double C, float D, signed char E, char F, void *G, double *H, int I, long long J) {
    printf("%d, %d, %f, %f, %d\n", a, b, C, D, E);
    printf("%d, %ld, %ld, %d, %lld\n", F, (long) G, (long) H, I, J);
}

int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Usage: %s <int> <short> <double> <float> <char> <char> <void*> <double> <int> <long long>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    short b = atoi(argv[2]);
    double C = atof(argv[3]);
    float D = atof(argv[4]);
    signed char E = atoi(argv[5]);
    char F = atoi(argv[6]);
    void *G = (void*)atol(argv[7]);
    double *H = (double*)atol(argv[8]);
    int I = atoi(argv[9]);
    long long J = atoll(argv[10]);

    printfn(a, b, C, D, E, F, G, H, I, J);
    return 0;
}
