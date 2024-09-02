// Modification timestamp: 2023-08-04 14:21:18
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00133.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    unsigned u;

    i = 1;
    i = -1;
    i = -1l;
    i = -1u;
    i = -1ll;
    i = 32766 + 1 & 3;
    i = (int) 32768 < 0;
    i = -1u < 0;

    u = 1;
    u = -1;
    u = -1l;
    u = -1u;
    u = -1ll;
    u = (unsigned) 32768 < 0;
    u = 32766 + 1 & 3;
    u = -1u < 0;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    // Assign arguments to variables
    i = atoi(argv[1]);
    u = atoi(argv[2]);

    return 0;
}
