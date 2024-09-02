// Modification timestamp: 2023-08-03 15:01:00
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00018.c

int main() {
    struct S { int x; int y; } s;
    struct S *p;

    p = &s;    
    s.x = 1;
    p->y = 2;
    return p->y + p->x - 3;
}
