// Modification timestamp: 2023-08-14 15:18:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49419.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct S {
  int w, x, y;
} *t;

int foo(int n, int f, int *s, int m) {
  int x, i, a;
  if (n == -1)
    return 0;
  for (x = n, i = 0; t[x].w == f && i < m; i++)
    x = t[x].x;
  if (i == m)
    abort();
  a = i + 1;
  for (x = n; i > 0; i--) {
    s[i] = t[x].y;
    x = t[x].x;
  }
  s[0] = x;
  return a;
}

int main(int argc, char *argv[]) {
  int s[3], i;
  struct S buf[3] = {{1, 1, 2}, {0, 0, 0}, {0, 0, 0}};
  t = buf;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg0 = atoi(argv[1]);

  if (foo(arg0, 1, s, 3) != 2)
    abort();
  if (s[0] != 1 || s[1] != 2)
    abort();
  return 0;
}
