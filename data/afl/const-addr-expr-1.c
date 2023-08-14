// Modification timestamp: 2023-08-14 14:19:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/const-addr-expr-1.c

#include <stdio.h>
#include <stdlib.h>
extern void abort();

typedef struct foo
{
    int uaattrid;
    char *name;
} FOO;

FOO Upgrade_items[] =
    {
        {1, "1"},
        {2, "2"},
        {0, NULL},
    };

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int *Upgd_minor_ID = (int *)&((Upgrade_items + 1)->uaattrid);
    int *Upgd_minor_ID1 = (int *)&((Upgrade_items)->uaattrid);

    if (*Upgd_minor_ID != atoi(argv[1]))
        abort();

    if (*Upgd_minor_ID1 != atoi(argv[1]))
        abort();

    return 0;
}

