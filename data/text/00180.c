
// Modification timestamp: 2023-08-04 14:34:27
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00180.c

#include <stdio.h>
#include <string.h>

int main() {
    char a[10];
    strcpy(a, "abcdef");
    printf("%s\n", &a[1]);

    return 0;
}

