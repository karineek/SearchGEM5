// Modification timestamp: 2023-08-04 14:25:01
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00149.c

struct S { int a; int b; };
struct S *s = &(struct S) { 1, 2 };

int main() {
    if (s->a != 1)
        return 1;
    if (s->b != 2)
        return 2;
    return 0;
}
