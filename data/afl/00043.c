// Modification timestamp: 2023-08-04 13:43:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00043.c

#include <stdio.h>
#include <stdlib.h>

struct s {
    int x;
    struct {
        int y;
        int z;
    } nest;
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <x> <y> <z>\n", argv[0]);
        return 1;
    }

    struct s v;
    v.x = atoi(argv[1]);
    v.nest.y = atoi(argv[2]);
    v.nest.z = atoi(argv[3]);

    if (v.x + v.nest.y + v.nest.z != 6)
        return 1;

    return 0;
}
