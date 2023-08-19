// Modification timestamp: 2023-08-04 14:22:19
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00137.c

#include <stdio.h>
#include <stdlib.h>

#define x(y) #y

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char *p;
    p = x(hello)  " is better than bye";
    return (*p == 'h') ? 0 : 1;
}
