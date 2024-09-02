// Modification timestamp: 2023-08-04 13:49:24
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00055.c

#include <stdio.h>
#include <stdlib.h>

enum E {
    x,
    y = 2,
    z,
};

int main(int argc, char *argv[]) {
    enum E e;

    if(argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if(x != 0)
        return 1;
    if(y != 2)
        return 2;
    if(z != 3)
        return 3;

    e = x;
    return e;
}
