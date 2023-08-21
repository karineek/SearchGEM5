// Modification timestamp: 2023-08-14 14:37:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/memcpy-1.c

#include <stdlib.h>
#include <string.h>

#if defined(STACK_SIZE)
#define MEMCPY_SIZE (STACK_SIZE / 3)
#else
#define MEMCPY_SIZE (1 << 17)
#endif

void *copy(void *o, const void *i, unsigned l)
{
    return memcpy(o, i, l);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <stack_size>\n", argv[0]);
        return 1;
    }

    unsigned i;
    unsigned char src[MEMCPY_SIZE];
    unsigned char dst[MEMCPY_SIZE];

    for (i = 0; i < MEMCPY_SIZE; i++)
        src[i] = (unsigned char)i, dst[i] = 0;

    (void)memcpy(dst, src, MEMCPY_SIZE / 128);

    for (i = 0; i < MEMCPY_SIZE / 128; i++)
        if (dst[i] != (unsigned char)i)
            abort();

    (void)memset(dst, 1, MEMCPY_SIZE / 128);

    for (i = 0; i < MEMCPY_SIZE / 128; i++)
        if (dst[i] != 1)
            abort();

    (void)memcpy(dst, src, MEMCPY_SIZE);

    for (i = 0; i < MEMCPY_SIZE; i++)
        if (dst[i] != (unsigned char)i)
            abort();

    (void)memset(dst, 0, MEMCPY_SIZE);

    for (i = 0; i < MEMCPY_SIZE; i++)
        if (dst[i] != 0)
            abort();

    (void)copy(dst, src, MEMCPY_SIZE / 128);

    for (i = 0; i < MEMCPY_SIZE / 128; i++)
        if (dst[i] != (unsigned char)i)
            abort();

    (void)memset(dst, 0, MEMCPY_SIZE);

    (void)copy(dst, src, MEMCPY_SIZE);

    for (i = 0; i < MEMCPY_SIZE; i++)
        if (dst[i] != (unsigned char)i)
            abort();

    exit(0);
}
