// Modification timestamp: 2023-08-14 15:26:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56205.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int a, b;
char c[128];

__attribute__((noinline, noclone)) static void f1(const char *fmt, ...) {
    va_list ap;
    asm volatile ("" : : : "memory");
    if (strcmp(fmt, "%s %d %s") != 0)
        abort();
    va_start(ap, fmt);
    if (strcmp(va_arg(ap, const char *), "foo") != 0
        || va_arg(ap, int) != 1
        || strcmp(va_arg(ap, const char *), "bar") != 0)
        abort();
    va_end(ap);
}

__attribute__((noinline, noclone)) static void f2(const char *fmt, va_list ap) {
    asm volatile ("" : : : "memory");
    if (strcmp(fmt, "baz") != 0
        || strcmp(va_arg(ap, const char *), "foo") != 0
        || va_arg(ap, double) != 12.0
        || va_arg(ap, int) != 26)
        abort();
}

static void f3(int x, char const *y, va_list z) {
    f1("%s %d %s", x ? "" : "foo", ++a, (y && *y) ? "bar" : "");
    if (y && *y)
        f2(y, z);
}

__attribute__((noinline, noclone)) void f4(int x, char const *y, ...) {
    va_list z;
    va_start(z, y);
    if (!x && *c == '\0')
        ++b;
    f3(x, y, z);
    va_end(z);
}

int main() {
    asm volatile ("" : : : "memory");
    f4(0, "baz", "foo", 12.0, 26);
    if (a != 1 || b != 1)
        abort();
    return 0;
}
