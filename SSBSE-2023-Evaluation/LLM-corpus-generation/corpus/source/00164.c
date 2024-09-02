// Modification timestamp: 2023-08-04 14:29:04
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00164.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int x;
    int y;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    d = atoi(argv[4]);
    e = atoi(argv[5]);
    f = atoi(argv[6]);

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
