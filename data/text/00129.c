// Modification timestamp: 2023-08-04 14:20:18
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00129.c

typedef struct s s;

struct s {
    struct s1 {
        int s;
        struct s2 {
            int s;
        } s1;
    } s;
} s2;

#define s s

int main(void) {
    undef s;
    goto s;
    struct s s;
    {
        int s;
        return s;
    }
    return s.s.s + s.s.s1.s;
s:
    {
        return 0;
    }
    return 1;
}
