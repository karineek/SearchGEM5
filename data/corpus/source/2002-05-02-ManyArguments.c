// Modification timestamp: 2023-08-14 17:11:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-02-ManyArguments.c

#include <stdio.h>

void printfn(int a, short b, double C, float D, signed char E, char F, void *G, double *H, int I, long long J) {
    printf("%d, %d, %f, %f, %d\n", a, b, C, D, E);
    printf("%d, %ld, %ld, %d, %lld\n", F, (long) G, (long) H, I, J);
}

int main(int argc, char *argv[]) {
    if (argc != 11) {
        printf("Usage: %s <a> <b> <C> <D> <E> <F> <G> <H> <I> <J>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    short b = atoi(argv[2]);
    double C = atof(argv[3]);
    float D = atof(argv[4]);
    signed char E = atoi(argv[5]);
    char F = atoi(argv[6]);
    void *G = (void *) atol(argv[7]);
    double *H = (double *) atol(argv[8]);
    int I = atoi(argv[9]);
    long long J = atoll(argv[10]);

    printfn(a, b, C, D, E, F, G, H, I, J);

    return 0;
}
