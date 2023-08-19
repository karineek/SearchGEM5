// Modification timestamp: 2023-08-14 15:16:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48717.c

#include <stdio.h>
#include <stdlib.h>

unsigned short foo(unsigned short x, unsigned short y) {
    return x + y;
}

void bar(unsigned short w, unsigned short *v) {
    *v = foo(~w, w);
}

int main(int argc, char *argv[]) {
    unsigned short v = 1;
    unsigned short w;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    w = atoi(argv[1]);

    bar(w, &v);

    if (v != (unsigned short)-1)
        abort();

    return 0;
}
