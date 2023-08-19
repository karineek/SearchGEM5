// Modification timestamp: 2023-08-14 16:02:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85756.c

#include <stdio.h>

#if __CHAR_BIT__ == 8 && __SIZEOF_SHORT__ == 2 && __SIZEOF_INT__ == 4
int a, c, *e, f, h = 10;
short b;
unsigned int p;

__attribute__((noipa)) void bar(int a) {
    asm volatile("" : : "r"(a) : "memory");
}

void foo(int j, int m, int n, int k, int* l) {
lab:
    p = m;
    m = -((~65535U | j) - n);
    f = b << ~(n - 8);
    n = (m || b) ^ f;
    j = p;
    if (p < m)
        *l = k < 3;
    if (!n)
        l = &k;
    if (c) {
        bar(a);
        goto lab;
    }
    if (!*l)
        *e = 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int j = atoi(argv[1]);
    int m = 430523;
    int n = 1;
    int k;
    int* l = &h;
    foo(j, m, n, k, l);

    return 0;
}
#else
int main() {
    return 0;
}
#endif
