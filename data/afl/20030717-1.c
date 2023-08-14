// Modification timestamp: 2023-08-14 12:47:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030717-1.c

#include <stdio.h>
#include <string.h>

struct A
{
    unsigned short a1;
    unsigned long a2;
};

struct B
{
    int b1, b2, b3, b4, b5;
};

struct C
{
    struct B c1[1];
    int c2, c3;
};

static
int foo(int x)
{
    return x < 0 ? -x : x;
}

int bar(struct C *x, struct A *y)
{
    int a = x->c3;
    const int b = y->a1 >> 9;
    const unsigned long c = y->a2;
    int d = a;
    unsigned long e, f;

    f = foo(c - x->c1[d].b4);
    do
    {
        if (d <= 0)
            d = x->c2;
        d--;

        e = foo(c - x->c1[d].b4);
        if (e < f)
            a = d;
    }
    while (d != x->c3);
    x->c1[a].b4 = c + b;
    return a;
}

int main(int argc, char *argv[])
{
    struct A a;
    struct C b;
    int c;

    if (argc != 3)
    {
        printf("Usage: %s <a1> <a2>\n", argv[0]);
        return 1;
    }

    a.a1 = atoi(argv[1]);
    a.a2 = atol(argv[2]);
    memset(&b, 0, sizeof(b));
    b.c1[0].b3 = 424242;
    b.c2 = 1;
    c = bar(&b, &a);
    return 0;
}


Note: This program requires two command line arguments: `a1` and `a2`. Make sure to pass them when executing the program.