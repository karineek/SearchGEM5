
// Modification timestamp: 2023-08-10 14:44:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/minisat/core/Solver.cc

#include <stdio.h>
#include <stdlib.h>

struct vec2 { double X, Y; };

void print(struct vec2 S) {
    printf("%f, %f\n", S.X, S.Y);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct vec2 U;
    U.X = atof(argv[1]);
    U.Y = atof(argv[2]);
    print(U);
    return 0;
}
