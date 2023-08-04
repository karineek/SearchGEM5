
// Modification timestamp: 2023-08-04 13:46:45
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00048.c

struct S {int a; int b;};
struct S s = { .b = 2, .a = 1};

int main() {
    if(s.a != 1)
        return 1;
    if(s.b != 2)
        return 2;
    return 0;
}
