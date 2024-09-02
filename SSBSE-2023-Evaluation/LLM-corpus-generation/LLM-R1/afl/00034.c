// Modification timestamp: 2023-08-03 18:01:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00034.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x;
    x = atoi(argv[1]);
    while (1)
        break;
    while (1) {
        if (x == 5) {
            break;
        }
        x = x + 1;
        continue;
    }
    for (;;) {
        if (x == 10) {
            break;
        }
        x = x + 1;
        continue;
    }
    do {
        if (x == 15) {
            break;
        }
        x = x + 1;
        continue;
    } while (1);
    return x - 15;
}
