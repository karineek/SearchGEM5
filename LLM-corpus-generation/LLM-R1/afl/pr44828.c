// Modification timestamp: 2023-08-14 15:13:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44828.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static signed char foo(signed char si1, signed char si2) {
    return si1 * si2;
}

int a;
int b;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if (foo(b, a) > 0) {
        abort();
    }
    return 0;
}
