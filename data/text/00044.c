
// Modification timestamp: 2023-08-04 13:43:15
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00044.c

struct T;

struct T {
    int x;
};

int main() {
    struct T v;
    { struct T { int z; }; }
    v.x = 2;
    if(v.x != 2)
        return 1;
    return 0;
}
