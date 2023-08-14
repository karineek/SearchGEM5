// Modification timestamp: 2023-08-14 15:30:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58365.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S
{
    volatile int a;
    int b, c, d, e;
} f;

static struct S g, h;

int i = 1;

char foo(void)
{
    return i;
}

static struct S bar(void)
{
    if (foo())
        return f;
    return g;
}

int main()
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    h = bar();
    f.b = x;
    if (h.b != y)
        abort();
    return 0;
}
