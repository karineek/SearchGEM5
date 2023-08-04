
// Modification timestamp: 2023-08-02 15:30:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00106.c

#include <stdio.h>
#include <stdlib.h>

struct S1 { int x; };
struct S2 { struct S1 s1; };

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct S2 s2;
    s2.s1.x = atoi(argv[1]);
    return 0;
}
