// Modification timestamp: 2023-08-04 13:43:02
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00043.c

struct s {
    int x;
    struct {
        int y;
        int z;
    } nest;
};

int main() {
    struct s v;
    v.x = 1;
    v.nest.y = 2;
    v.nest.z = 3;
    if (v.x + v.nest.y + v.nest.z != 6)
        return 1;
    return 0;
}
