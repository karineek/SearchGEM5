// Modification timestamp: 2023-08-14 12:37:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021011-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char buf[64];
    int i;

    strcpy(buf, argv[1]);
    if (strcmp(buf, argv[1]) != 0)
        abort();

    for (i = 0; i < 16; ++i) {
        strcpy(buf + i, argv[1]);
        if (strcmp(buf + i, argv[1]) != 0)
            abort();
    }

    return 0;
}
