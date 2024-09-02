// Modification timestamp: 2023-08-04 15:02:31
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00217.c

#include <stdio.h>
#include <stdlib.h>

int printf(const char *, ...);
char t[] = "012345678";

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <value> <value2> <value3>\n", argv[0]);
        return 1;
    }

    char *data = t;
    unsigned long long r = atoi(argv[1]);
    unsigned a = atoi(argv[2]);
    unsigned long long b = atoi(argv[3]);

    *(unsigned*)(data + r) += a - b;

    printf("data = \"%s\"\n", data);
    return 0;
}
