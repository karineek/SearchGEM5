// Modification timestamp: 2023-08-03 17:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00025.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *p;
    p = argv[1];
    return strlen(p) - 5;
}
