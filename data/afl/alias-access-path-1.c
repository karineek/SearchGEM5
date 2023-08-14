// Modification timestamp: 2023-08-14 13:59:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-access-path-1.c

#include <stdio.h>
#include <stdlib.h>

struct a {
    int val;
} a = {1}, a2;
struct b {
    struct a a;
};
int val;
struct c {
    struct b b;
} *cptr = (void *)&val;

int main(void) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    cptr->b.a.val = atoi(argv[1]);
    val = 2;
    a2 = cptr->b.a;
    if (a2.val == a.val) {
        printf("Error: a2.val is equal to a.val\n");
        return 1;
    }
    return 0;
}
