c
// Modification timestamp: 2023-08-10 14:44:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/StructArgs.c

#include <stdio.h>
#include <stdlib.h>

struct vec2 { double X, Y; };

void print(struct vec2 S, struct vec2 T) {
    printf("%f, %f, %f, %f\n", S.X, S.Y, T.X, T.Y);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <U.X> <U.Y> <V.X> <V.Y>\n", argv[0]);
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
