
// Modification timestamp: 2023-08-10 14:44:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/minisat/core/Solver.cc

#include <stdio.h>

struct vec2 { double X, Y; };

void print(struct vec2 S) {
    printf("%f, %f\n", S.X, S.Y);
}

int main() {
    struct vec2 U;
    U.X = .5; U.Y = 1.2;
    print(U);
    return 0;
}
