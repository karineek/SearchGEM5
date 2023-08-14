// Modification timestamp: 2023-08-14 15:20:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51581-1.c

#include <stdio.h>
#include <stdlib.h>

#define N 4096

int a[N], c[N];
unsigned int b[N], d[N];

__attribute__((noinline, noclone)) void f1(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = a[i] / 3;
}

__attribute__((noinline, noclone)) void f2(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++)
        d[i] = b[i] / 3;
}

__attribute__((noinline, noclone)) void f3(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = a[i] / 18;
}

__attribute__((noinline, noclone)) void f4(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++)
        d[i] = b[i] / 18;
}

__attribute__((noinline, noclone)) void f5(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = a[i] / 19;
}

__attribute__((noinline, noclone)) void f6(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++)
        d[i] = b[i] / 19;
}

#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
__attribute__((noinline, noclone)) void f7(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = (int) ((unsigned long long) (a[i] * 0x55555556LL) >> 32) - (a[i] >> 31);
}

__attribute__((noinline, noclone)) void f8(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++)
        d[i] = ((unsigned int) ((b[i] * 0xaaaaaaabULL) >> 32) >> 1);
}

__attribute__((noinline, noclone)) void f9(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = (((int) ((unsigned long long) (a[i] * 0x38e38e39LL) >> 32)) >> 2) - (a[i] >> 31);
}

__attribute__((noinline, noclone)) void f10(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++)
        d[i] = (unsigned int) ((b[i] * 0x38e38e39ULL) >> 32) >> 2;
}

__attribute__((noinline, noclone)) void f11(int* a, int* c) {
    int i;
    for (i = 0; i < N; i++)
        c[i] = (((int) ((unsigned long long) (a[i] * 0x6bca1af3LL) >> 32)) >> 3) - (a[i] >> 31);
}

__attribute__((noinline, noclone)) void f12(unsigned int* b, unsigned int* d) {
    int i;
    for (i = 0; i < N; i++) {
        unsigned int tmp = (b[i] * 0xaf286bcbULL) >> 32;
        d[i] = (((b[i] - tmp) >> 1) + tmp) >> 4;
    }
}
#endif

int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < N; i++) {
        asm ("");
        a[i] = i - N / 2;
        b[i] = i;
    }
    a[0] = -__INT_MAX__ - 1;
    a[1] = -__INT_MAX__;
    a[N - 1] = __INT_MAX__;
    b[N - 1] = ~0;
    f1(a, c);
    f2(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 3 || d[i] != b[i] / 3)
            abort();
    f3(a, c);
    f4(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 18 || d[i] != b[i] / 18)
            abort();
    f5(a, c);
    f6(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 19 || d[i] != b[i] / 19)
            abort();
#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
    f7(a, c);
    f8(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 3 || d[i] != b[i] / 3)
            abort();
    f9(a, c);
    f10(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 18 || d[i] != b[i] / 18)
            abort();
    f11(a, c);
    f12(b, d);
    for (i = 0; i < N; i++)
        if (c[i] != a[i] / 19 || d[i] != b[i] / 19)
            abort();
#endif
    return 0;
}
