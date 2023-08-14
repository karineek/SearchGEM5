// Modification timestamp: 2023-08-14 15:16:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48571-1.c

#include <stdio.h>
#include <stdlib.h>

#define S (sizeof(int))

unsigned int c[624];
void __attribute__((noinline)) bar(void)
{
    unsigned int i;
    /* Obfuscated c[i] = c[i-1] * 2.  */
    for (i = 1; i < 624; ++i)
        *(unsigned int *)((void *)c + (__SIZE_TYPE__) i * S)
                = 2 * *(unsigned int *)((void *)c + ((__SIZE_TYPE__) i +
                                                       ((__SIZE_TYPE__) - S) / S) * S);
}

extern void abort(void);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    unsigned int i, j;
    for (i = 0; i < 624; ++i)
        c[i] = atoi(argv[i + 1]);
    bar();
    j = atoi(argv[625]);
    for (i = 0; i < 624; ++i)
    {
        if (c[i] != j)
            abort();
        j = j * 2;
    }
    return 0;
}
