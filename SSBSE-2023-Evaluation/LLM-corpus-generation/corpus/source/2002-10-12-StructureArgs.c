// Modification timestamp: 2023-08-14 17:11:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-12-StructureArgs.c
#include <stdlib.h>

#include <stdio.h>

struct vec2 { double X, Y; };

void print(struct vec2 S, struct vec2 T) {
    printf("%f, %f, %f, %f\n", S.X, S.Y, T.X, T.Y);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
        return 1;
    }

    struct vec2 U, V;
    U.X = atof(argv[1]);
    U.Y = atof(argv[2]);
    V.X = atof(argv[3]);
    V.Y = atof(argv[4]);
    print(U, V);
    return 0;
}
