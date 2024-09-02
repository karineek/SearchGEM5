// Modification timestamp: 2023-08-14 12:36:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020810-1.c
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct A
{
    long x;
};

struct R
{
    struct A a, b;
};

struct R R = {100, 200};

void f(struct R r)
{
    if (r.a.x != R.a.x || r.b.x != R.b.x)
        abort();
}

struct R g(void)
{
    return R;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct R r;
    f(R);
    r = g();
    if (r.a.x != R.a.x || r.b.x != R.b.x)
        abort();
    return 0;
}
