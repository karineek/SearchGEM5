// Modification timestamp: 2023-08-14 16:08:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/scal-to-vec1.c

#include <stdio.h>
#include <stdlib.h>

#define vector(elcount, type) \
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

volatile int one = 1;

int main(int argc, char *argv[]) {
#define fvec_2 (vector(4, float)){2., 2., 2., 2.}
#define dvec_2 (vector(2, double)){2., 2.}

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int one = atoi(argv[1]);

  vector(8, short) v0 = {one, 1, 2, 3, 4, 5, 6, 7};
  vector(8, short) v1;

  vector(4, float) f0 = {1., 2., 3., 4.};
  vector(4, float) f1, f2;

  vector(2, double) d0 = {1., 2.};
  vector(2, double) d1, d2;

  v1 = one + v0;
  check(short, 8, v0, v1, one, +, l);
  v1 = one - v0;
  check(short, 8, v0, v1, one, -, l);
  v1 = one * v0;
  check(short, 8, v0, v1, one, *, l);
  v1 = one / v0;
  check(short, 8, v0, v1, one, /, l);
  v1 = one % v0;
  check(short, 8, v0, v1, one, %, l);
  v1 = one ^ v0;
  check(short, 8, v0, v1, one, ^, l);
  v1 = one & v0;
  check(short, 8, v0, v1, one, &, l);
  v1 = one | v0;
  check(short, 8, v0, v1, one, |, l);
  v1 = one << v0;
  check(short, 8, v0, v1, one, <<, l);
  v1 = one >> v0;
  check(short, 8, v0, v1, one, >>, l);

  v1 = v0 + one;
  check(short, 8, v0, v1, one, +, r);
  v1 = v0 - one;
  check(short, 8, v0, v1, one, -, r);
  v1 = v0 * one;
  check(short, 8, v0, v1, one, *, r);
  v1 = v0 / one;
  check(short, 8, v0, v1, one, /, r);
  v1 = v0 % one;
  check(short, 8, v0, v1, one, %, r);
  v1 = v0 ^ one;
  check(short, 8, v0, v1, one, ^, r);
  v1 = v0 & one;
  check(short, 8, v0, v1, one, &, r);
  v1 = v0 | one;
  check(short, 8, v0, v1, one, |, r);

  f1 = one + f0;
  f2 = fvec_2 + f0;
  veccompare(float, 4, f1, f2);
  f1 = one - f0;
  f2 = fvec_2 - f0;
  veccompare(float, 4, f1, f2);
  f1 = one * f0;
  f2 = fvec_2 * f0;
  veccompare(float, 4, f1, f2);
  f1 = one / f0;
  f2 = fvec_2 / f0;
  veccompare(float, 4, f1, f2);

  f1 = f0 + one;
  f2 = f0 + fvec_2;
  veccompare(float, 4, f1, f2);
  f1 = f0 - one;
  f2 = f0 - fvec_2;
  veccompare(float, 4, f1, f2);
  f1 = f0 * one;
  f2 = f0 * fvec_2;
  veccompare(float, 4, f1, f2);
  f1 = f0 / one;
  f2 = f0 / fvec_2;
  veccompare(float, 4, f1, f2);

  d1 = one + d0;
  d2 = dvec_2 + d0;
  veccompare(double, 2, d1, d2);
  d1 = one - d0;
  d2 = dvec_2 - d0;
  veccompare(double, 2, d1, d2);
  d1 = one * d0;
  d2 = dvec_2 * d0;
  veccompare(double, 2, d1, d2);
  d1 = one / d0;
  d2 = dvec_2 / d0;
  veccompare(double, 2, d1, d2);

  d1 = d0 + one;
  d2 = d0 + dvec_2;
  veccompare(double, 2, d1, d2);
  d1 = d0 - one;
  d2 = d0 - dvec_2;
  veccompare(double, 2, d1, d2);
  d1 = d0 * one;
  d2 = d0 * dvec_2;
  veccompare(double, 2, d1, d2);
  d1 = d0 / one;
  d2 = d0 / dvec_2;
  veccompare(double, 2, d1, d2);

  return 0;
}
