// Modification timestamp: 2023-08-14 17:33:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//DuffsDevice.c

#include <stdio.h>

void sum(register short *to, register short *from, register int count) {
    register int n = (count + 7) / 8;
    switch (count % 8) {
        case 0: do { *to += *from++;
        case 7:     *to += *from++;
        case 6:     *to += *from++;
        case 5:     *to += *from++;
        case 4:     *to += *from++;
        case 3:     *to += *from++;
        case 2:     *to += *from++;
        case 1:     *to += *from++;
        } while (--n > 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    short Array[100];
    for (int i = 0; i != 100; ++i) {
        Array[i] = i;
    }

    short Sum = atoi(argv[1]);
    sum(&Sum, Array, 100);

    printf("Sum is %d\n", Sum);
    return 0;
}

