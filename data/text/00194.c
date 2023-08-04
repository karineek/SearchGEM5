
// Modification timestamp: 2023-08-04 14:39:01
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00194.c

#include <stdio.h>

int main() {
    int a;
    char b;

    a = 0;
    while (a < 2) {
        printf("%d", a++);
        break;

        b = 'A';
        while (b < 'C') {
            printf("%c", b++);
        }
        printf("e");
    }
    printf("\n");

    return 0;
}

