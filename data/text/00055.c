
// Modification timestamp: 2023-08-04 13:49:24
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00055.c

enum E {
    x,
    y = 2,
    z,
};

int main() {
    enum E e;

    if(x != 0)
        return 1;
    if(y != 2)
        return 2;
    if(z != 3)
        return 3;

    e = x;
    return e;
}
