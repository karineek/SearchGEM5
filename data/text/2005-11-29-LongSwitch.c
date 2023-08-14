c
// Modification timestamp: 2023-08-10 15:12:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Programs/single-source/2005-11-29-LongSwitch.c

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
