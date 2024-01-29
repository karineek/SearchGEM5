// Modification timestamp: 2023-08-14 12:50:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031012-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(STACK_SIZE) && STACK_SIZE < 16000
#define ARRAY_SIZE (STACK_SIZE / 2)
#define STRLEN     (ARRAY_SIZE - 9)
#else
#define ARRAY_SIZE 15000
#define STRLEN     13371
#endif

extern void *memset(void *, int, __SIZE_TYPE__);
extern void abort(void);

static void foo(int argc, char* argv[])
{
    char a[ARRAY_SIZE];

    a[0] = 0;
    memset(&a[0], 0xCD, STRLEN);
    a[STRLEN] = 0;
    if (strlen(a) != STRLEN)
        abort();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    foo(argc, argv);
    return 0;
}
