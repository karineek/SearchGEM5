
// Modification timestamp: 2023-08-02 17:40:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00049.c

int x = 10;

struct S {int a; int *p;};
struct S s = { .p = &x, .a = 1};

int main() {
    if(s.a != 1)
        return 1;
    if(*s.p != 10)
        return 2;
    return 0;
}
