// Modification timestamp: 2023-08-14 17:30:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-Value-1.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int32_t main(int32_t argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char a = argv[1][0];
    short b = atoi(argv[2]);
    short d = atoi(argv[3]);
    short h = atoi(argv[4]);
    char c[6];
    int32_t e = atoi(argv[5]);
    int32_t f = atoi(argv[6]);
    int32_t g = atoi(argv[7]);
    int32_t j = atoi(argv[8]);
    int32_t i = 8;

    for (; f; f = a) {
        g = (5);
        for (; g <= 32; ++g) {
            i = 6;
            for (; i < -4; i++)
                while (7 > d)
                    if (c[b]) {
                        break;
                    }
        L:
            if (j) {
                break;
            }
        }
    }
    e = 0;
    for (; e; e = 900) {
        d++;
        for (; h;)
            goto L;
    }
    printf("%" PRId32, e);
    return 0;
}

