// Modification timestamp: 2023-08-14 16:03:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr88693.c
// C
#include <stdio.h>
#include <string.h>

__attribute__((noipa)) void foo(char *p) {
  if (strlen(p) != 9)
    abort();
}

__attribute__((noipa)) void quux(char *p) {
  int i;
  for (i = 0; i < 100; i++)
    if (p[i] != 'x')
      abort();
}

__attribute__((noipa)) void qux(char *p) {
  memset(p, 'x', 100);
  quux(p);
}

__attribute__((noipa)) void bar(char *p) {
  static unsigned char u[9] = "abcdefghi";
  char b[100];
  memcpy(b, u, sizeof(u));
  b[sizeof(u)] = 0;
  foo(b);
}

__attribute__((noipa)) void baz(char *p) {
  static unsigned char u[] = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
  char b[100];
  memcpy(b, u, sizeof(u));
  b[sizeof(u)] = 0;
  foo(b);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char b[100];
  qux(b);
  bar(b);
  baz(b);
  return 0;
}
