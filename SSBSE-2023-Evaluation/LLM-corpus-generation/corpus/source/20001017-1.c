// Modification timestamp: 2023-08-14 11:52:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001017-1.c

#include <stdio.h>
#include <stdlib.h>

void bug(double *Cref, char transb, int m, int n, int k,
         double a, double *A, int fdA, double *B, int fdB,
         double b, double *C, int fdC)
{
    if (C != Cref)
        abort();
}

int main(int argc, char *argv[])
{
    if (argc != 14)
    {
        printf("Usage: %s <Cref> <transb> <m> <n> <k> <a> <A> <fdA> <B> <fdB> <b> <C> <fdC>\n", argv[0]);
        return 1;
    }

    double *Cref = (double *)argv[1];
    char transb = argv[2][0];
    int m = atoi(argv[3]);
    int n = atoi(argv[4]);
    int k = atoi(argv[5]);
    double a = atof(argv[6]);
    double *A = (double *)argv[7];
    int fdA = atoi(argv[8]);
    double *B = (double *)argv[9];
    int fdB = atoi(argv[10]);
    double b = atof(argv[11]);
    double *C = (double *)argv[12];
    int fdC = atoi(argv[13]);

    bug(Cref, transb, m, n, k, a, A, fdA, B, fdB, b, C, fdC);

    return 0;
}
