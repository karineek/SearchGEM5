// Modification timestamp: 2023-08-14 14:42:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr15262-1.c

#include <stdio.h>
#include <stdlib.h>

struct A
{
    int t;
    int i;
};

int foo(int argc, char *argv[]) { return 3; }

int main(int argc, char *argv[]) {
    struct A loc, *locp;
    float f, g, *p;
    int T355, *T356;

    /* Avoid the partial hack in TBAA that would consider memory tags if
       the program had no addressable symbols.  */
    f = 3;
    g = 2;
    p = foo(argc, argv) ? &g : &f;
    if (*p > 0.0)
        g = 1;

    /* Store into *locp and cache its current value.  */
    locp = malloc(sizeof(*locp));
    locp->i = 10;
    T355 = locp->i;

    /* Take the address of one of locp's fields and write to it.  */
    T356 = &locp->i;
    *T356 = 1;

    /* Read the recently stored value.  If TBAA fails, this will appear
       as a redundant load that will be replaced with '10'.  */
    T355 = locp->i;
    if (T355 != 1)
        abort();

    return 0;
}
