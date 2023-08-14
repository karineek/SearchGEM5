// Modification timestamp: 2023-08-14 13:07:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060930-2.c

/* PR middle-end/29272 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);

struct S {
    struct S *s;
} s;

struct T {
    struct T *t;
} t;

static inline void foo(void *s) {
    struct T *p = s;
    memcpy(&p->t, &t.t, sizeof(t.t));
}

void *__attribute__((noinline)) bar(void *p, struct S *q) {
    q->s = &s;
    foo(p);
    return q->s;
}

int main(void) {
    t.t = &t;
    if (bar(&s, &s) != (void *)&t)
        abort();
    return 0;
}
