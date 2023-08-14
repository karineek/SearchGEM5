// Modification timestamp: 2023-08-14 12:51:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031215-1.c

#include <stdio.h>

typedef struct {
    int c, l;
    char ch[3];
} pstr;

const pstr ao = {2, 2, "OK"};
const pstr * const a = &ao;

void test1(void) {
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = 0;
    }
}

void test2(void) {
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = -1;
    }
}

void test3(void) {
    if (a->ch[a->l]) {
        ((char *)a->ch)[a->l] = 1;
    }
}

int main(void) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);

    test1();
    test2();
    test3();

    return 0;
}
