// Modification timestamp: 2023-08-14 15:45:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67781.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned uint32_t;
#endif

#ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ uint8_t;
#else
typedef unsigned char uint8_t;
#endif

struct {
    uint32_t a;
    uint8_t b;
} s;

int pr67781(uint32_t a, uint8_t b) {
    uint32_t c = (a << 8) | b;
    return c;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <a> <b>\n", argv[0]);
        return 1;
    }

    uint32_t a = atoi(argv[1]);
    uint8_t b = atoi(argv[2]);

    s.a = a;
    s.b = b;

    if (sizeof(uint32_t) * __CHAR_BIT__ != 32)
        return 0;

    if (pr67781(a, b) != (s.a << 8) | s.b)
        __builtin_abort();
    return 0;
}
