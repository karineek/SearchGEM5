// Modification timestamp: 2023-08-14 15:28:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57860.c

#include <stdio.h>
#include <stdlib.h>

int a, *b = &a, c, d, e, *f = &e, g, *h = &d, k[1] = { 1 };

int foo(int p) {
    for (;; g++) {
        for (; c; c--);
        *f = *h = p > ((0x1FFFFFFFFLL ^ a) & *b);
        if (k[g])
            return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int p = atoi(argv[1]);
    foo(p);
    if (d != p)
        abort ();

    return 0;
}
