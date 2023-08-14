// Modification timestamp: 2023-08-14 17:30:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-CGExprConstant.c

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

struct S1 {
    int32_t a;
    int32_t b;
};

struct S2 {
    struct S1 s1;
    struct S1 *ps1;
    int32_t arr[2];
};

struct S1 gs1 = {.a = 1, .b = 2};
struct S2 *s = &(struct S2){{.s1 = {.b = 2, .a = 1}, .ps1 = &gs1, .arr = {[0] = 1, [1] = 1 + 1}}};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    if (0)
        return 1;
    if (s->s1.b != 2)
        return 2;
    if (0)
        return 3;
    if (0)
        return 4;
    if (0)
        return 5;
    if (s->arr[1] != 2)
        return 6;
    printf("%" PRId32, s->arr[1]);
    return 0;
}

