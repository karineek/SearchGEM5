// Modification timestamp: 2023-08-03 18:01:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00033.c
#include <stdio.h>
#include <stdlib.h>

int g;

int effect() {
    g = 1;
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int x;

    g = atoi(argv[1]);
    x = atoi(argv[2]);
    if (x && effect())
        return 1;
    if (g)
        return 2;
    g = atoi(argv[1]);
    x = atoi(argv[2]);
    if (x && effect()) {
        if (g != 1)
            return 3;
    } else {
        return 4;
    }
    g = 0;
    x = atoi(argv[2]);
    if (x || effect()) {
        if (g)
            return 5;
    } else {
        return 6;
    }
    g = atoi(argv[1]);
    x = atoi(argv[2]);
    if (x || effect()) {
        if (g != 1)
            return 7;
    } else {
        return 8;
    }
    return 0;
}
