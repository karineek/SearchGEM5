// Modification timestamp: 2023-08-14 16:08:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/scal-to-vec2.c

#include <stdio.h>
#include <stdlib.h>

#define vector(elcount, type)  \
__attribute__((vector_size((elcount)*sizeof(type)))) type

#define vidx(type, vec, idx) (*((type *) &(vec) + idx))

#define operl(a, b, op) (a op b)
#define operr(a, b, op) (b op a)

#define check(type, count, vec0, vec1, num, op, lr) \
do {\
    int __i; \
    for (__i = 0; __i < count; __i++) {\
        if (vidx (type, vec1, __i) != oper##lr (num, vidx (type, vec0, __i), op)) \
            __builtin_abort (); \
    }\
} while (0)

#define veccompare(type, count, v0, v1) \
do {\
    int __i; \
    for (__i = 0; __i < count; __i++) { \
        if (vidx (type, v0, __i) != vidx (type, v1, __i)) \
            __builtin_abort (); \
    } \
} while (0)


long __attribute__ ((noinline)) vlng () {   return (long)42; }
int  __attribute__ ((noinline)) vint () {   return (int) 43; }
short __attribute__ ((noinline)) vsrt () {   return (short)42; }
char __attribute__ ((noinline)) vchr () {    return (char)42; }


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    vector(16, char) c0 = {argc, 1, 2, 3, 4, 5, 6, 7, argc, 1, 2, 3, 4, 5, 6, 7};
    vector(16, char) c1;

    vector(8, short) s0 = {argc, 1, 2, 3, 4, 5, 6, 7};
    vector(8, short) s1;

    vector(4, int) i0 = {argc, 1, 2, 3};
    vector(4, int) i1;

    vector(2, long) l0 = {argc, 1};
    vector(2, long) l1;

    c1 = atoi(argv[1]) + c0; check(char, 16, c0, c1, atoi(argv[1]), +, l);

    s1 = atoi(argv[1]) + s0; check(short, 8, s0, s1, atoi(argv[1]), +, l);
    s1 = atoi(argv[1]) + s0; check(short, 8, s0, s1, atoi(argv[1]), +, l);

    i1 = atoi(argv[1]) * i0; check(int, 4, i0, i1, atoi(argv[1]), *, l);
    i1 = atoi(argv[1]) * i0; check(int, 4, i0, i1, atoi(argv[1]), *, l);
    i1 = atoi(argv[1]) * i0; check(int, 4, i0, i1, atoi(argv[1]), *, l);

    l1 = atoi(argv[1]) * l0; check(long, 2, l0, l1, atoi(argv[1]), *, l);
    l1 = atoi(argv[1]) * l0; check(long, 2, l0, l1, atoi(argv[1]), *, l);
    l1 = atoi(argv[1]) * l0; check(long, 2, l0, l1, atoi(argv[1]), *, l);
    l1 = atoi(argv[1]) * l0; check(long, 2, l0, l1, atoi(argv[1]), *, l);

    return 0;
}
