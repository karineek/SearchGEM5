
// Modification timestamp: 2023-08-10 15:42:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/MallocBench/espresso/main.c

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#pragma ms_struct on

typedef struct
{
    void *pv;
    int l;
} Foo;

typedef struct
{
    void *pv1;
    Foo foo;
    unsigned short fInited : 1;
    void *pv2;
} PackOddity;

#pragma ms_struct off

int main(int argc, char *argv[])
{
    #pragma unused(argc, argv)
    int sizeof_packoddity = sizeof(PackOddity);
    int offsetof_foo = offsetof(PackOddity, foo);
    int offsetof_pv2 = offsetof(PackOddity, pv2);
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    sizeof_packoddity = atoi(argv[1]);
    if (sizeof_packoddity != 40)
    abort();
    if (offsetof_foo != 8)
    abort();
    if (offsetof_pv2 != 32)
    abort();
    return 0;
}
