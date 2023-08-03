// Modification timestamp: 2023-08-03 16:15:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00019.c

int main() {
    struct S { struct S *p; int x; } s;

    s.x = 0;
    s.p = &s;
    return s.p->p->p->p->p->x;
}
