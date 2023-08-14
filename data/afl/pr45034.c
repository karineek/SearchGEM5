// Modification timestamp: 2023-08-14 15:14:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr45034.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static void fixnum_neg(signed char x, signed char *py, int *pv)
{
    unsigned char ux, uy;

    ux = (unsigned char)x;
    uy = -ux;
    *py = (uy <= 127) ? (signed char)uy : (-(signed char)(255 - uy) - 1);
    *pv = (x == -128) ? 1 : 0;
}

void __attribute__((noinline)) foo(int x, int y, int v)
{
    if (y < -128 || y > 127)
        abort();
}

int test_neg(void)
{
    signed char x, y;
    int v, err;

    err = 0;
    x = atoi(argv[1]);
    for (;;)
    {
        fixnum_neg(x, &y, &v);
        foo((int)x, (int)y, v);
        if ((v && x != -128) || (!v && x == -128))
            ++err;
        if (x == 127)
            break;
        ++x;
    }
    return err;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (sizeof(char) != 1)
        return 0;
    if (test_neg() != 0)
        abort();
    return 0;
}
