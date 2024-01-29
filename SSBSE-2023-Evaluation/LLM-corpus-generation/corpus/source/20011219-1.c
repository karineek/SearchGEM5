// Modification timestamp: 2023-08-14 12:07:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011219-1.c

#include <stdio.h>
#include <stdlib.h>

enum X { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q };

void bar(const char* x, int y, const char* z) {
}

long foo(enum X x, const void* y) {
    long a;

    switch (x) {
        case K:
            a = *(long*)y;
            break;
        case L:
            a = *(long*)y;
            break;
        case M:
            a = *(long*)y;
            break;
        case N:
            a = *(long*)y;
            break;
        case O:
            a = *(long*)y;
            break;
        default:
            bar("foo", 1, "bar");
    }
    return a;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long i = 24;
    int arg = atoi(argv[1]);

    if (foo(arg, &i) != 24)
        abort();
    exit(0);
}
