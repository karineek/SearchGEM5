
// Modification timestamp: 2023-08-10 15:10:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/Bitfield/2005-07-15-Bitfield-ABI.c

#include <stdio.h>
#include <stdlib.h>

struct X {
    int Q :6;
    int A : 4;
    int Z : 22;
};

void test(struct X *P, int A) {
    P->A = A;
}

int main(int argc, char *argv[]) {
    union {
        int Y;
        struct X Z;
    } U;
    U.Y = ~0;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int A = atoi(argv[1]);
    test(&U.Z, A);
    printf("%x\n", U.Y);
    return 0;
}
