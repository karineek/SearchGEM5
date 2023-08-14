// Modification timestamp: 2023-08-14 13:01:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050119-1.c

#include <stdio.h>
#include <stdlib.h>

typedef enum { A, B, C, D } E;

struct S {
  E __attribute__ ((mode (__byte__))) a;
  E __attribute__ ((mode (__byte__))) b;
  E __attribute__ ((mode (__byte__))) c;
  E __attribute__ ((mode (__byte__))) d;
};

extern void abort (void);
extern void exit (int);

void foo(struct S *s) {
  if (s->a != s->b)
    abort();
  if (s->c != C)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S s[2];
  s[0].a = atoi(argv[1]);
  s[0].b = atoi(argv[2]);
  s[0].c = C;
  s[0].d = D;
  s[1].a = D;
  s[1].b = C;
  s[1].c = B;
  s[1].d = A;
  foo(s);
  exit(0);
}
