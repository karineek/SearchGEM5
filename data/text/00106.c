// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00106.c

struct S1 { int x; };
struct S2 { struct S1 s1; };

int main() {
    struct S2 s2;
    s2.s1.x = 1;
    return 0;
}
