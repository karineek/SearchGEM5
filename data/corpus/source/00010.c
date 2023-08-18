// Modification timestamp: 2023-08-03 10:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00010.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);

    start:
        printf("Starting the program with x = %d\n", x);
        goto next;
        return 1;
    success:
        printf("Program executed successfully with x = %d\n", x);
        return 0;
    next:
        printf("Going to the 'success' label with x = %d\n", x);
    foo:
        printf("Going to the 'success' label from 'foo' with x = %d\n", x);
        goto success;
        return 1;
}
