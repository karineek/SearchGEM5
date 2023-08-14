// Modification timestamp: 2023-08-14 15:45:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67037.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long (*extfunc)();

static inline void lstrcpynW(short *d, const short *s, int n) {
    unsigned int count = n;

    while ((count > 1) && *s) {
        count--;
        *d++ = *s++;
    }
    if (count) *d = 0;
}

int __attribute__((noinline,noclone))
badfunc(int u0, int u1, int u2, int u3,
  short *fsname, unsigned int fsname_len)
{
    static const short ntfsW[] = {'N','T','F','S',0};
    char superblock[2048+3300];
    int ret = 0;
    short *p;

    if (extfunc())
        return 0;
    p = (void *)extfunc();
    if (p != 0)
        goto done;

    extfunc(superblock);

    lstrcpynW(fsname, ntfsW, fsname_len);

    ret = 1;
done:
    return ret;
}

static long f() {
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    short buf[6];
    extfunc = f;
    return !badfunc(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), buf, atoi(argv[5]));
}
