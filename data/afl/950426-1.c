// Modification timestamp: 2023-08-14 13:41:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950426-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tag {
  int m1;
  char *m2[5];
} s1, *p1;

int i;

int func1(int *p) { return(*p); }

void foo (char *s) {}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s1.m1 = atoi(argv[1]);
  p1 = &s1;

  if (func1(&p1->m1) == -1)
    foo("ok");
  else
    abort();

  i = 3;
  s1.m2[3] = "123";

  if (strlen((p1->m2[i])++) == 3)
    foo("ok");
  else
    abort();

  exit(0);
}
