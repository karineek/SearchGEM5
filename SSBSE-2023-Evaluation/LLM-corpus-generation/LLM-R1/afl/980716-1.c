// Modification timestamp: 2023-08-14 13:51:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980716-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void stub(int num, ...) {
    va_list ap;
    char *end;
    int i;

    for (i = 0; i < num; i++) {
        va_start(ap, num);
        while (1) {
            end = va_arg(ap, char *);
            if (!end)
                break;
        }
        va_end(ap);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    stub(1, argv[1], argv[2], argv[3], (char *)0);
    exit(0);
}
