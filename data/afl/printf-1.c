// Modification timestamp: 2023-08-14 16:05:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/printf-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

#define test(ret, args...) \
    printf(args);           \
    if (printf(args) != ret) \
        abort();

    test(5, argv[1]);
    test(6, argv[1]);
    test(1, argv[1]);
    test(0, argv[1]);
    test(5, "%s", argv[1]);
    test(6, "%s", argv[1]);
    test(1, "%s", argv[1]);
    test(0, "%s", argv[1]);
    test(1, "%c", argv[1][0]);
    test(7, "%s\n", argv[1]);
    test(2, "%d\n", atoi(argv[1]));

    return 0;
}
