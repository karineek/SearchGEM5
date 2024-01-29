// Modification timestamp: 2023-08-14 13:01:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050119-2.c

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

E foo(struct S *s) {
  if (s->a != s->b)
    abort();
  if (s->c != C)
    abort();
  return s->d;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S s[2];
  s[0].a = atoi(argv[1]);
  s[0].b = atoi(argv[2]);
  s[0].c = atoi(argv[3]);
  s[0].d = atoi(argv[4]);
  s[1].a = atoi(argv[5]);
  s[1].b = atoi(argv[6]);
  s[1].c = atoi(argv[7]);
  s[1].d = atoi(argv[8]);

  if (foo(s) != D)
    abort();
  exit(0);
}
