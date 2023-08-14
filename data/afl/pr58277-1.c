// Modification timestamp: 2023-08-14 15:29:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58277-1.c

#include <stdio.h>

extern void abort(void);

static int a[2];
int b, c, d, *e, f, g, h, **i = &e, k, l = 1, n, o, p;
static int **volatile j = &e;
const int m;
char u;

int bar() {
  u = 0;
  return m;
}

__attribute__((noinline, noclone)) void baz() {
  asm("");
}

int foo() {
  int t1;
  g = bar();
  if (l)
    ;
  else
    for (;; h++) {
      *i = 0;
      o = *e = 0;
      if (p) {
        f = 0;
        return 0;
      }
      for (;; k++) {
        int *t2 = 0;
        int *const *t3[] = {
            0,      0,      0,      0,      0,      0,      0,      0,      0,
            &t2,    0,      0,      &t2,    &t2,    &t2,    &t2,    &t2,    0,
            0,      0,      0,      0,      0,      0,      &t2,    0,      0,
            0,      0,      0,      0,      0,      0,      0,      0,      0,
            &t2,    0,      0,      0,      0,      0,      0,      &t2,    &t2,
            &t2,    &t2,    &t2,    0,      0,      0,      0,      0,      0,
            0,      &t2,    0,      0,      0,      &t2,    0,      0,      0,
            &t2,    0,      &t2,    0,      0,      &t2,    0,      0,      0,
            0,      0,      &t2,    0,      0,      0,      0,      0,      &t2,
            0,      0,      0,      0,      &t2,    &t2,    0,      0,      0,
            0,      &t2,    0,      0,      0,      0,      0,      0,      0,
            &t2,    0,      0,      0,      0,      0,      &t2,    0,      0,
            0,      &t2,    &t2};
        int *const **t4[] = {&t3[0]};
        **i = 0;
        if (**j)
          break;
        u = 0;
      }
      *i = *j;
      t1 = 0;
      for (; t1 < 5; t1++)
        *i = *j;
    }
  *j = 0;
  return 1;
}

int main(int argc, char *argv[]) {
  int t5;
  a[0] = atoi(argv[1]);

  {
    int *t6[6] = {&d, &d};
    for (n = 1; n; n--)
      if (foo()) {
        int *t7[] = {0};
        d = 0;
        for (; u < 1; u++)
          *i = *j;
        *i = 0;
        *i = 0;
        int t8[5] = {0};
        *i = &t8[0];
        int *const *t9 = &t6[0];
        int *const **t10 = &t9;
        *t10 = &t7[0];
      }
  }
  u = 0;
  for (; b; b++)
    for (t5 = 0; t5 < 10; t5++)
      c = a[a[a[a[a[a[a[a[c]]]]]]]];

  baz();

  if (!a[a[a[a[a[a[a[a[a[a[a[a[a[a[a[u]]]]]]]]]]]]]]])
    abort();

  return 0;
}


Note: Since there are no string literals or constants that need to be replaced with arguments in the given code, the modified code remains the same as the original code.