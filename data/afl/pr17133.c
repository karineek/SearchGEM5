// Modification timestamp: 2023-08-14 14:43:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr17133.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo = 0;
void *bar = 0;
unsigned int baz = 100;

void *pure_alloc(int *foo, void **bar, unsigned int baz)
{
    void *res;

    while (1)
    {
        res = (void *)((((unsigned int)(*foo + *bar))) & ~1);
        *foo += 2;
        if (*foo < baz)
            return res;
        *foo = 0;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    foo = atoi(argv[1]);
    pure_alloc(&foo, &bar, baz);
    if (!foo)
        abort();
    return 0;
}
