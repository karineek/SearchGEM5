// Modification timestamp: 2023-08-04 14:29:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00164.c

#include <stdio.h>

int main() {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int x;
    int y;

    a = 12;
    b = 34;
    c = 56;
    d = 78;
    e = 0;
    f = 1;

    printf("%d\n", c + d);
    printf("%d\n", (y = c + d));
    printf("%d\n", e || e && f);
    printf("%d\n", e || f && f);
    printf("%d\n", e && e || f);
    printf("%d\n", e && f || f);
    printf("%d\n", a && f | f);
    printf("%d\n", a | b ^ c & d);
    printf("%d, %d\n", a == a, a == b);
    printf("%d, %d\n", a != a, a != b);
    printf("%d\n", a != b && c != d);
    printf("%d\n", a + b * c / f);
    printf("%d\n", a + b * c / f);
    printf("%d\n", (4 << 4));
    printf("%d\n", (64 >> 4));

    return 0;
}

