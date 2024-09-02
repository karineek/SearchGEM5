// Modification timestamp: 2023-08-04 14:39:01
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00194.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int a;
    char b;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
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
