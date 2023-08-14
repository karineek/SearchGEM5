
// Modification timestamp: 2023-08-10 15:10:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/Bitfield/2005-07-15-Bitfield-ABI.c

struct X {
    int Q :6;
    int A : 4;
    int Z : 22;
};

void test(struct X *P, int A) {
    P->A = A;
}

extern int printf(const char *str, ...);

int main() {
    union {
        int Y;
        struct X Z;
    } U;
    U.Y = ~0;
    test(&U.Z, 0);
    printf("%x\n", U.Y);
    return 0;
}
