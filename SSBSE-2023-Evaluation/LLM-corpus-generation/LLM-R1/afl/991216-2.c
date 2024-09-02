// Modification timestamp: 2023-08-14 13:58:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991216-2.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define AFTER 0x55

void test(int n, ...) {
    va_list ap;
    int i;

    va_start(ap, n);
    for (i = 2; i <= n; i++) {
        if (va_arg(ap, int) != i)
            abort();
    }

    if (va_arg(ap, long long) != *argv[2])
        abort();

    if (va_arg(ap, int) != AFTER)
        abort();

    va_end(ap);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    test(1, *argv[1], AFTER);
    test(2, 2, *argv[1], AFTER);
    test(3, 2, 3, *argv[1], AFTER);
    test(4, 2, 3, 4, *argv[1], AFTER);
    test(5, 2, 3, 4, 5, *argv[1], AFTER);
    test(6, 2, 3, 4, 5, 6, *argv[1], AFTER);
    test(7, 2, 3, 4, 5, 6, 7, *argv[1], AFTER);
    test(8, 2, 3, 4, 5, 6, 7, 8, *argv[1], AFTER);
    return 0;
}
