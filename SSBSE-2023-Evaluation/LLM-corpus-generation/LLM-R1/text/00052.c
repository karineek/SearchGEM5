// Modification timestamp: 2023-08-04 13:48:29
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00052.c

int main() {
    struct T { int x; };
    {
        struct T s;
        s.x = 0;
        return s.x;
    }
}
