// Modification timestamp: 2023-08-14 13:52:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990128-1.c

#include <stdio.h>
#include <stdlib.h>

extern int printf(const char *, ... );

struct s {
    struct s *n;
};

struct s *p;
struct s ss;

#define MAX 10
struct s sss[MAX];
int count = 0;

void sub(struct s *p, struct s **pp);
int look(struct s *p, struct s **pp);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct s *pp;
    struct s *next;
    int i;

    p = &ss;
    next = p;
    for (i = 0; i < MAX; i++) {
        next->n = &sss[i];
        next = next->n;
    }
    next->n = 0;

    sub(p, &pp);
    if (count != MAX + 2)
        abort();

    exit(0);
}

void sub(struct s *p, struct s **pp) {
    for (; look(p, pp);) {
        if (p)
            p = p->n;
        else
            break;
    }
}

int look(struct s *p, struct s **pp) {
    for (; p; p = p->n)
        ;
    *pp = p;
    count++;
    return (1);
}
