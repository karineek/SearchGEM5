// Modification timestamp: 2023-08-14 11:58:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010409-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __SIZE_TYPE__ size_t;

extern size_t strlen(const char *s);

typedef struct A {
    int a, b;
} A;

typedef struct B {
    struct A **a;
    int b;
} B;

A *a;
int b = 1, c;
B d[1];

void foo(A *x, const char *y, int z)
{
    c = y[4] + z * 25;
}

A *bar(const char *v, int w, int x, const char *y, int z)
{
    if (w)
        abort ();
    exit (0);
}

void test(const char *x, int *y)
{
    foo(d->a[d->b], "test", 200);
    d->a[d->b] = bar(x, b ? 0 : 65536, strlen(x), "test", 201);
    d->a[d->b]->a++;
    if (y)
        d->a[d->b]->b = *y;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <string> <integer>\n", argv[0]);
        return 1;
    }

    d->b = 0;
    d->a = &a;

    const char *x = argv[1];
    int *y = (int *) malloc(sizeof(int));
    *y = atoi(argv[2]);

    test(x, y);

    free(y);

    return 0;
}
