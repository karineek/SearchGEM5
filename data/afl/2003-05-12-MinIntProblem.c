
// Modification timestamp: 2023-08-10 14:46:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2003-05-12-MinIntProblem.c

#include <stdio.h>
#include <stdlib.h>

void foo(int X) {
    if (X + 1 < 0)
        printf("success\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int X = atoi(argv[1]);
    foo(X);
    return 0;
}
