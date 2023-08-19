// Modification timestamp: 2023-08-04 14:12:59
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00115.c

#include <stdio.h>
#include <stdlib.h>

#define B "b"

char s[] = "a" B "c";

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int arg = atoi(argv[1]);

    if (s[0] != 'a')
        return arg + 1;
    if (s[1] != 'b')
        return arg + 2;
    if (s[2] != 'c')
        return arg + 3;
    if (s[3] != '\0')
        return arg + 4;
    
    return arg;
}
