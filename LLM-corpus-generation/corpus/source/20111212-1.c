// Modification timestamp: 2023-08-14 13:19:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20111212-1.c
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

struct event {
    struct {
        unsigned int sec;
    } sent __attribute__((packed));
};

void __attribute__((noinline,noclone)) frob_entry(char *buf)
{
    struct event event;

    memcpy(&event, buf, sizeof(event));
    if (event.sent.sec < 64) {
        event.sent.sec = -1U;
        memcpy(buf, &event, sizeof(event));
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    union {
        char buf[1 + sizeof(struct event)];
        int align;
    } u;

    memset(&u, 0, sizeof(u));

    frob_entry(&u.buf[1]);

    return 0;
}
