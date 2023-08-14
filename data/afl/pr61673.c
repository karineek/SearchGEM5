// Modification timestamp: 2023-08-14 15:39:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61673.c

#include <stdio.h>
#include <stdlib.h>

char e;

__attribute__((noinline, noclone)) void bar(char x) {
  if (x != argv[1][0] && x != (char)argv[1][1])
    __builtin_abort();
}

__attribute__((noinline, noclone)) void foo(const char *x) {
  char d = x[0];
  int c = d;
  if ((c >= 0 && c <= 0x7f) == 0)
    e = d;
  bar(d);
}

__attribute__((noinline, noclone)) void baz(const char *x) {
  char d = x[0];
  int c = d;
  if ((c >= 0 && c <= 0x7f) == 0)
    e = d;
}

int main(int argc, char *argv[]) {
  const char c[] = {argv[1][0], argv[1][1]};
  e = argv[2][0];
  foo(c);
  if (e != argv[2][0])
    __builtin_abort();
  foo(c + 1);
  if (e != (char)argv[2][1])
    __builtin_abort();
  e = argv[2][0];
  baz(c);
  if (e != argv[2][0])
    __builtin_abort();
  baz(c + 1);
  if (e != (char)argv[2][1])
    __builtin_abort();
  return 0;
}
