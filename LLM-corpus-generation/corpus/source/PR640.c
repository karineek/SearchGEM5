// Modification timestamp: 2023-08-14 17:33:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//PR640.c
#include <stdlib.h>

#include <stdarg.h>
#include <stdio.h>

static int test_stdarg_va(void* p1, ...)
{
    va_list ap;
    unsigned long l;
    int i1, i2;
    void* p2;
    va_start(ap, p1);
    i1 = va_arg(ap, int);
    l = va_arg(ap, unsigned long);
    i2 = va_arg(ap, int);
    p2 = va_arg(ap, void *);
    va_end(ap);
    return p1 == p2 && i1 == 1 && l == 0x76214365ul && i2 == 2;
}

#if defined(__GNUC__) && \
    ((__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))

static int test_stdarg_builtin_va(void* p1, ...)
{
    __builtin_va_list ap;
    unsigned long l;
    int i1, i2;
    void* p2;
    __builtin_va_start(ap, p1);
    i1 = __builtin_va_arg(ap, int);
    l = __builtin_va_arg(ap, unsigned long);
    i2 = __builtin_va_arg(ap, int);
    p2 = __builtin_va_arg(ap, void *);
    __builtin_va_end(ap);
    return p1 == p2 && i1 == 1 && l == 0x76214369ul && i2 == 2;
}

#endif

static int test_stdarg(int r, char c1, char c2)
{
    unsigned long l = 0x76214365ul; // Replace constant with argument assignment
    void* p = &r; // Replace constant with argument assignment

    if (test_stdarg_va(&r, c1, l, c2, p) != 1)
        return 0;
#if defined(__GNUC__) && \
    ((__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 4))
    if (test_stdarg_builtin_va(&r, c1, 0x76214369ul, c2, &r) != 1)
        return 0;
#endif
    return r & 1;
}


int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s <char1> <char2>\n", argv[0]);
        return 1;
    }
    char c1 = argv[1][0]; // Convert first argument to char
    char c2 = argv[2][0]; // Convert second argument to char

    if (test_stdarg(1, c1, c2) != 1) {
        printf("ERROR\n");
        return 1;
    }
    printf("All done.\n");
    return 0;
}
