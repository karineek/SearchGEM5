// Modification timestamp: 2023-08-04 14:00:46
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00079.c

#define x(y) ((y) + 1)

int main() {
    int x;
    int y;

    y = 0;
    x = x(y);

    if (x != 1)
        return 1;

    return 0;
}
