// Modification timestamp: 2023-08-03 16:17:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00024.c

typedef struct { int x; int y; } s;

s v;

int main() {
    v.x = 1;
    v.y = 2;
    return 3 - v.x - v.y;
}
