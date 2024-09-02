// Modification timestamp: 2023-08-14 13:23:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20180112-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef __UINT32_TYPE__ u32;

u32 bug(u32 *result, u32 ss, u32 d)
{
    u32 tt = d & 0x00800000;
    u32 r = tt << 8;
    
    r = (r >> 31) | (r << 1);
    
    u32 u = r ^ ss;
    u32 off = u >> 1;
    
    *result = tt;
    return off;
}

int main(int argc, char *argv[])
{
    if (argc != 5) {
        printf("Usage: %s <ss> <d> <tt> <off>\n", argv[0]);
        return 1;
    }
    
    u32 ss = atoi(argv[1]);
    u32 d = atoi(argv[2]);
    u32 tt = atoi(argv[3]);
    u32 off = atoi(argv[4]);
    
    u32 l;
    u32 result = bug(&l, ss, d);
    if (result != off)
        abort();
    return 0;
}
