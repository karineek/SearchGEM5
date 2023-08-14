// Modification timestamp: 2023-08-14 13:50:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980608-1.c

/* { dg-options "-fgnu89-inline" } */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

void f1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o) {
    return;
}

inline void debug(const char *msg, ...) {
    va_list ap;
    va_start(ap, msg);

    f1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

    if (va_arg(ap, int) != 101)
        abort();
    if (va_arg(ap, int) != 102)
        abort();
    if (va_arg(ap, int) != 103)
        abort();
    if (va_arg(ap, int) != 104)
        abort();
    if (va_arg(ap, int) != 105)
        abort();
    if (va_arg(ap, int) != 106)
        abort();

    va_end(ap);
}

int main(int argc, char *argv[]) {
    if (argc != 8) {
        printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7>\n", argv[0]);
        return 1;
    }

    int arg1 = atoi(argv[1]);
    int arg2 = atoi(argv[2]);
    int arg3 = atoi(argv[3]);
    int arg4 = atoi(argv[4]);
    int arg5 = atoi(argv[5]);
    int arg6 = atoi(argv[6]);
    int arg7 = atoi(argv[7]);

    debug("%d %d %d  %d %d %d\n", arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    exit(0);
}
