
// Modification timestamp: 2023-08-10 16:09:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/SingleSource/UnitTests/sumarray2d.c

#include <stdio.h>
#include <stdlib.h>

int SumArray(int Array[][100], unsigned int NumI, unsigned int NumJ) {
    unsigned i, j;
    int Result = 0;

    for (i = 0; i < NumI; i++)
        for (j = 0; j < NumJ; j++)
            Result += Array[i][j];

    return Result;
}

int main(int argc, char *argv[]) {
    int Array[100][100];
    unsigned int i, j;

    if (argc != 4) {
        printf("Usage: %s <NumI> <NumJ> <Element>\n", argv[0]);
        return 1;
    }

    unsigned int NumI = atoi(argv[1]);
    unsigned int NumJ = atoi(argv[2]);
    int Element = atoi(argv[3]);

    for (i = 0; i < NumI; i++)
        for (j = 0; j < NumJ; j++)
            Array[i][j] = Element;

    printf("Sum(Array[%d,%d] = %d\n", NumI, NumJ, SumArray(Array, NumI, NumJ));

    return 0;
}
