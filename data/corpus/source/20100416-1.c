// Modification timestamp: 2023-08-14 13:18:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100416-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int movegt(int x, int y, long long a) {
    int i;
    int ret = 0;
    for (i = 0; i < y; i++) {
        if (a >= (long long) atoi(argv[1])) {
            ret = x;
        } else {
            ret = y;
        }
    }
    return ret;
}

struct test {
    long long val;
    int ret;
} tests[] = {
    { (long long) atoi(argv[2]), -1 },
    { (long long) atoi(argv[3]), 1 },
    { (long long) atoi(argv[4]), -1 },
    { (long long) atoi(argv[5]), -1 },
    { (long long) atoi(argv[6]), 1 },
};

int main(int argc, char *argv[]) {
    int i;
    if (argc != 7) {
        printf("Usage: %s <value> <value> <value> <value> <value> <value>\n", argv[0]);
        return 1;
    }
    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (movegt(-1, 1, tests[i].val) != tests[i].ret)
            abort();
    }
    return 0;
}
