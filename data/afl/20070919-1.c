// Modification timestamp: 2023-08-14 13:10:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070919-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef __SIZE_TYPE__ size_t;

int memcmp(const void *, const void *, size_t);
void abort(void);

void __attribute__((noinline)) bar(void *x, void *y)
{
    struct S
    {
        char w[8];
    } *p = x, *q = y;
    if (memcmp(p->w, "zyxwvut", 8) != 0)
        abort();
    if (memcmp(q[0].w, "abcdefg", 8) != 0)
        abort();
    if (memcmp(q[1].w, "ABCDEFG", 8) != 0)
        abort();
    if (memcmp(q[2].w, "zyxwvut", 8) != 0)
        abort();
    if (memcmp(q[3].w, "zyxwvut", 8) != 0)
        abort();
}

void __attribute__((noinline)) foo(void *x, int y)
{
    struct S
    {
        char w[y];
    } *p = x, a;
    int i;
    a = ({ struct S b;
           memcpy(&b, &(p[2]), sizeof(struct S));
           memcpy(&(p[3]), &b, sizeof(struct S));
           b; });
    bar(&a, x);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct S
    {
        char w[8];
    } p[4] = {"abcdefg", "ABCDEFG", "zyxwvut", "ZYXWVUT"};
    int y = atoi(argv[1]);
    foo(p, y);
    return 0;
}
