// Modification timestamp: 2023-08-14 15:49:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69447.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

u64 __attribute__((noinline, noclone))
foo(u8 u8_0, u16 u16_0, u64 u64_0, u8 u8_1, u16 u16_1, u64 u64_1, u64 u64_2, u8 u8_3, u64 u64_3)
{
	u64_1 *= 0x7730;
	u64_3 *= u64_3;
	u16_1 |= u64_3;
	u64_3 -= 2;
	u8_3 /= u64_2;
	u8_0 |= 3;
	u64_3 %= u8_0;
	u8_0 -= 1;
	return u8_0 + u16_0 + u64_0 + u8_1 + u16_1 + u64_1 + u8_3 + u64_3;
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    unsigned x = foo(1, 1, 1, 1, 1, 1, 1, 1, 1);
    if (x != 0x7737)
		__builtin_abort();
    return 0;
}
