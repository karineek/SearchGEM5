// Modification timestamp: 2023-08-14 17:17:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-11-29-LongSwitch.c

#include <stdio.h>
#include <stdlib.h>

int foo(long long v) {
    switch (v) {
    case 0:
        return 1;
    case -1:
        return 2;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    long long v = atoll(argv[1]);
    int r = foo(v);
    printf("foo = %d\n", r);
    return r;
}
