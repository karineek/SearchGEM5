// Modification timestamp: 2023-08-03 15:00:30
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00017.c

int main() {
    struct { int x; int y; } s;

    s.x = 3;
    s.y = 5;
    return s.y - s.x - 2;
}
