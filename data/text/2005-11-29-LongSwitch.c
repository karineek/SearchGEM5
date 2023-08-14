// Modification timestamp: 2023-08-14 17:17:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-11-29-LongSwitch.c
// PR671

#include <stdio.h>

int foo(long long v) {
    switch (v) {
    case 0:
        return 1;
    case -1:
        return 2;
    }
    return 0;
}

int main() {
    int r = foo(4294967295LL);
    printf("foo = %d\n", r);
    return r;
}
