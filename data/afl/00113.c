
// Modification timestamp: 2023-08-04 14:12:38
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00113.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <a> <f>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    float f = a + 1;

    return f == a;
}
