// Modification timestamp: 2023-08-14 12:48:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030828-2.c

#include <stdio.h>
#include <stdlib.h>

struct rtx_def {
    int code;
};

int main(int argc, char *argv[]) {
    int tmp[2];
    struct rtx_def *r, s;
    int *p, *q;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    r = &s;
    r->code = atoi(argv[1]);

    p = tmp;
    q = p + 1;
    *q = 0;
    tmp[1] = atoi(argv[2]);
    if (*q != atoi(argv[3])) {
        abort();
    }
    exit(0);
}
