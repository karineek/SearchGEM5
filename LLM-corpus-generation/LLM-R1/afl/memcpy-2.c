// Modification timestamp: 2023-08-14 14:37:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/memcpy-2.c

#include <stdlib.h>
#include <string.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof (long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY (10 * sizeof (long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof (long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

#define SEQUENCE_LENGTH 31

static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u1, u2;

int main(int argc, char *argv[]) {

    for (int off1 = 0; off1 < MAX_OFFSET; off1++) {
        for (int off2 = 0; off2 < MAX_OFFSET; off2++) {
            for (int len = 1; len < MAX_COPY; len++) {

                for (int i = 0, c = 'A'; i < MAX_LENGTH; i++, c++) {
                    u1.buf[i] = 'a';
                    if (c >= 'A' + SEQUENCE_LENGTH)
                        c = 'A';
                    u2.buf[i] = c;
                }

                char *p = memcpy(u1.buf + off1, u2.buf + off2, len);
                if (p != u1.buf + off1)
                    abort();

                char *q = u1.buf;
                for (int i = 0; i < off1; i++, q++) {
                    if (*q != 'a')
                        abort();
                }

                for (int i = 0, c = 'A' + off2; i < len; i++, q++, c++) {
                    if (c >= 'A' + SEQUENCE_LENGTH)
                        c = 'A';
                    if (*q != c)
                        abort();
                }

                for (int i = 0; i < MAX_EXTRA; i++, q++) {
                    if (*q != 'a')
                        abort();
                }
            }
        }
    }

    return 0;
}

