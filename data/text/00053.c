// Modification timestamp: 2023-08-04 13:48:47
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00053.c

int main() {
    struct T { int x; } s1;
    s1.x = 1;
    {
        struct T { int y; } s2;
        s2.y = 1;
        if (s1.x - s2.y != 0)
            return 1;
    }
    return 0;
}
