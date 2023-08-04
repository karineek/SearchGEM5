
// Modification timestamp: 2023-08-04 14:25:57
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00153.c

#define x f
#define y() f

typedef struct { int f; } S;

int main() {
    S s;
    s.x = 0;
    return s.y();
}
