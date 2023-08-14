// Modification timestamp: 2023-08-14 13:56:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990811-1.c

#include <stdio.h>
#include <stdlib.h>

struct s {
    long a;
    int b;
};

int foo(int x, void *y) {
    switch (x) {
    case 0:
        return ((struct s *)y)->a;
    case 1:
        return *(signed char *)y;
    case 2:
        return *(short *)y;
    }
    abort();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct s s;
    short sh[10];
    signed char c[10];
    int i;

    s.a = atoi(argv[1]);
    s.b = atoi(argv[2]);
    for (i = 0; i < 10; i++) {
        sh[i] = i;
        c[i] = i;
    }

    if (foo(0, &s) != 1)
        abort();
    if (foo(1, c + atoi(argv[3])) != atoi(argv[3]))
        abort();
    if (foo(2, sh + atoi(argv[3])) != atoi(argv[3]))
        abort();
    exit(0);
}
