// Modification timestamp: 2023-08-14 15:37:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60822.c

#include <stdio.h>
#include <stdlib.h>

struct X {
    char fill0[800000];
    int a;
    char fill1[900000];
    int b;
};

int __attribute__((noinline,noclone))
Avg(struct X *p, int s)
{
    return (s * (long long)(p->a + p->b)) >> 17;
}

struct X x;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int s = atoi(argv[1]);
    x.a = s << 17;
    x.b = (s + 1) << 17;

    if (Avg(&x, 1) != (s + s + 1)) {
        printf("Error: Expected result is %d\n", (s + s + 1));
        return 1;
    }

    return 0;
}
