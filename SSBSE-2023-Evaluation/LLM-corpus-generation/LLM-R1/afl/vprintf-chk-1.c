// Modification timestamp: 2023-08-14 17:03:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vprintf-chk-1.c

#ifndef test
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

volatile int should_optimize;

int __attribute__((noinline)) __vprintf_chk(int flag, const char *fmt, va_list ap) {
    #ifdef __OPTIMIZE__
    if (should_optimize)
        abort();
    #endif
    should_optimize = 1;
    return vprintf(fmt, ap);
}

void inner(int x, ...) {
    va_list ap, ap2;
    va_start(ap, x);
    va_start(ap2, x);

    switch (x) {
        case 0:
            should_optimize = 0;
            __vprintf_chk(1, "hello", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "hello", ap2) != 5)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 1:
            should_optimize = 1;
            __vprintf_chk(1, "hello\n", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "hello\n", ap2) != 6)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 2:
            should_optimize = 1;
            __vprintf_chk(1, "a", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "a", ap2) != 1)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 3:
            should_optimize = 1;
            __vprintf_chk(1, "", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "", ap2) != 0)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 4:
            should_optimize = 0;
            __vprintf_chk(1, "%s", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%s", ap2) != 5)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 5:
            should_optimize = 0;
            __vprintf_chk(1, "%s", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%s", ap2) != 6)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 6:
            should_optimize = 0;
            __vprintf_chk(1, "%s", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%s", ap2) != 1)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 7:
            should_optimize = 0;
            __vprintf_chk(1, "%s", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%s", ap2) != 0)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 8:
            should_optimize = 0;
            __vprintf_chk(1, "%c", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%c", ap2) != 1)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 9:
            should_optimize = 0;
            __vprintf_chk(1, "%s\n", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%s\n", ap2) != 7)
                abort();
            if (!should_optimize)
                abort();
            break;
        case 10:
            should_optimize = 0;
            __vprintf_chk(1, "%d\n", ap);
            if (!should_optimize)
                abort();
            should_optimize = 0;
            if (__vprintf_chk(1, "%d\n", ap2) != 2)
                abort();
            if (!should_optimize)
                abort();
            break;
        default:
            abort();
    }

    va_end(ap);
    va_end(ap2);
}

int main(void) {
    inner(0, 5, 0, "hello", 0);
    inner(1, 6, 1, "hello\n", 1);
    inner(2, 1, 1, "a", 2);
    inner(3, 0, 1, "", 3);
    inner(4, 5, 0, "%s", 4, "hello");
    inner(5, 6, 0, "%s", 5, "hello\n");
    inner(6, 1, 0, "%s", 6, "a");
    inner(7, 0, 0, "%s", 7, "");
    inner(8, 1, 0, "%c", 8, 'x');
    inner(9, 7, 0, "%s\n", 9, "hello\n");
    inner(10, 2, 0, "%d\n", 10, 0);
    return 0;
}
#endif
