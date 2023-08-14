// Modification timestamp: 2023-08-14 13:13:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080122-1.c

#include <stdio.h>

typedef unsigned short u16;
typedef unsigned char u8;

static void do_segfault(u8 in_buf[], const u8 out_buf[], const int len) {
    int i;

    for (i = 0; i < len; i++) {
        asm("");

        in_buf[2 * i] = (out_buf[2 * i] | out_buf[(2 * i) + 1] << 8) & 0xFF;

        asm("");

        in_buf[(2 * i) + 1] = (out_buf[2 * i] | out_buf[(2 * i) + 1] << 8) >> 8;

        asm("");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    u8 outbuf[32] = "buffer     ";
    u8 inbuf[32] = "\f";
    int len = atoi(argv[1]);

    asm("");
    do_segfault(inbuf, outbuf, len);
    asm("");

    return 0;
}

