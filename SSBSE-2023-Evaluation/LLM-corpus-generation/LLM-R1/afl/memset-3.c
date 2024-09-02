// Modification timestamp: 2023-08-14 14:39:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/memset-3.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_OFFSET (sizeof(long long))
#define MAX_COPY 15
#define MAX_EXTRA (sizeof(long long))
#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u;

char A = 'A';

void reset() {
    int i;

    for (i = 0; i < MAX_LENGTH; i++)
        u.buf[i] = 'a';
}

void check(int off, int len, int ch) {
    char *q;
    int i;

    q = u.buf;
    for (i = 0; i < off; i++, q++)
        if (*q != 'a')
            abort();

    for (i = 0; i < len; i++, q++)
        if (*q != ch)
            abort();

    for (i = 0; i < MAX_EXTRA; i++, q++)
        if (*q != 'a')
            abort();
}

int main(int argc, char *argv[]) {
    int len;
    char *p;

    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    /* off == 0 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf, '\0', len);
        if (p != u.buf)
            abort();
        check(0, len, '\0');

        p = memset(u.buf, A, len);
        if (p != u.buf)
            abort();
        check(0, len, 'A');

        p = memset(u.buf, 'B', len);
        if (p != u.buf)
            abort();
        check(0, len, 'B');
    }

    /* off == 1 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 1, '\0', len);
        if (p != u.buf + 1)
            abort();
        check(1, len, '\0');

        p = memset(u.buf + 1, A, len);
        if (p != u.buf + 1)
            abort();
        check(1, len, 'A');

        p = memset(u.buf + 1, 'B', len);
        if (p != u.buf + 1)
            abort();
        check(1, len, 'B');
    }

    /* off == 2 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 2, '\0', len);
        if (p != u.buf + 2)
            abort();
        check(2, len, '\0');

        p = memset(u.buf + 2, A, len);
        if (p != u.buf + 2)
            abort();
        check(2, len, 'A');

        p = memset(u.buf + 2, 'B', len);
        if (p != u.buf + 2)
            abort();
        check(2, len, 'B');
    }

    /* off == 3 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 3, '\0', len);
        if (p != u.buf + 3)
            abort();
        check(3, len, '\0');

        p = memset(u.buf + 3, A, len);
        if (p != u.buf + 3)
            abort();
        check(3, len, 'A');

        p = memset(u.buf + 3, 'B', len);
        if (p != u.buf + 3)
            abort();
        check(3, len, 'B');
    }

    /* off == 4 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 4, '\0', len);
        if (p != u.buf + 4)
            abort();
        check(4, len, '\0');

        p = memset(u.buf + 4, A, len);
        if (p != u.buf + 4)
            abort();
        check(4, len, 'A');

        p = memset(u.buf + 4, 'B', len);
        if (p != u.buf + 4)
            abort();
        check(4, len, 'B');
    }

    /* off == 5 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 5, '\0', len);
        if (p != u.buf + 5)
            abort();
        check(5, len, '\0');

        p = memset(u.buf + 5, A, len);
        if (p != u.buf + 5)
            abort();
        check(5, len, 'A');

        p = memset(u.buf + 5, 'B', len);
        if (p != u.buf + 5)
            abort();
        check(5, len, 'B');
    }

    /* off == 6 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 6, '\0', len);
        if (p != u.buf + 6)
            abort();
        check(6, len, '\0');

        p = memset(u.buf + 6, A, len);
        if (p != u.buf + 6)
            abort();
        check(6, len, 'A');

        p = memset(u.buf + 6, 'B', len);
        if (p != u.buf + 6)
            abort();
        check(6, len, 'B');
    }

    /* off == 7 */
    for (len = 0; len < MAX_COPY; len++) {
        reset();

        p = memset(u.buf + 7, '\0', len);
        if (p != u.buf + 7)
            abort();
        check(7, len, '\0');

        p = memset(u.buf + 7, A, len);
        if (p != u.buf + 7)
            abort();
        check(7, len, 'A');

        p = memset(u.buf + 7, 'B', len);
        if (p != u.buf + 7)
            abort();
        check(7, len, 'B');
    }

    return 0;
}
