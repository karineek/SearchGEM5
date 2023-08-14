
// Modification timestamp: 2023-08-10 15:51:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/C/2003-05-14-initialize-string.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char title[] = argv[1];
    printf("%s", title);
    return 0;
}
