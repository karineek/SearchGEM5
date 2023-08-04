
// Modification timestamp: 2023-08-04 13:41:09
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00040.c

#include <stdlib.h>

int N;
int *t;

int chk(int x, int y) {
    int i;
    int r;

    for (r = i = 0; i < N; i++) {
        r = r + t[x + N * i];
        r = r + t[i + N * y];
        if (x + i < N & y + i < N)
            r = r + t[x + i + N * (y + i)];
        if (x + i < N & y - i >= 0)
            r = r + t[x + i + N * (y - i)];
        if (x - i >= 0 & y + i < N)
            r = r + t[x - i + N * (y + i)];
        if (x - i >= 0 & y - i >= 0)
            r = r + t[x - i + N * (y - i)];
    }
    return r;
}

int go(int n, int x, int y) {
    if (n == N) {
        N++;
        return 0;
    }
    for (; y < N; y++) {
        for (; x < N; x++)
            if (chk(x, y) == 0) {
                t[x + N * y]++;
                go(n + 1, x, y);
                t[x + N * y]--;
            }
        x = 0;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    N = atoi(argv[1]);
    t = calloc(N * N, sizeof(int));
    go(0, 0, 0);
    if (N != 92)
        return 1;
    return 0;
}
