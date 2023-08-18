// Modification timestamp: 2023-08-14 12:37:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021015-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

char g_list[] = { '1' };

void g(void *p, char *list, int length, char **elementPtr, char **nextPtr) {
    if (*nextPtr != list) {
        abort();
    }

    **nextPtr = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char *list = g_list;
    char *element;
    int i, length = atoi(argv[1]);

    for (i = 0; *list != 0; i++) {
        char *prevList = list;
        g(0, list, length, &element, &list);
        length -= (list - prevList);
    }

    return 0;
}
