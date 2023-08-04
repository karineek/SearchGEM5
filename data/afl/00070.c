
// Modification timestamp: 2023-08-04 13:56:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00070.c

#ifndef DEF
int x = 0;
#endif

#define DEF

#ifndef DEF
X
#endif

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }
    
    int x = atoi(argv[1]);
    return x;
}
