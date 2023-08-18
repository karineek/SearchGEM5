// Modification timestamp: 2023-08-14 13:49:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-3.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char lookup_table[257];

static int build_lookup(unsigned char *pattern)
{
    int m;
    m = strlen(pattern) - 1;
    memset(lookup_table, ++m, 257);
    return m;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (build_lookup(argv[1]) != 4)
        abort();
    else
        exit(0);
}

