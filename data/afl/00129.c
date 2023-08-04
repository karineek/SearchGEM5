
// Modification timestamp: 2023-08-04 14:20:18
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00129.c

#include <stdio.h>
#include <stdlib.h>

typedef struct s s;

struct s {
    struct s1 {
        int s;
        struct s2 {
            int s;
        } s1;
    } s;
} s2;

#define s s

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    undef s;
    goto s;
    struct s s;
    {
        int s;
        return s;
    }
    return x + x;
s:
    {
        return 0;
    }
    return 1;
}
