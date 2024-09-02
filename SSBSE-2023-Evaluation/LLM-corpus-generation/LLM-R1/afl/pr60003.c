// Modification timestamp: 2023-08-14 15:37:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr60003.c

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf jmp_buf;

void baz() {
  longjmp(jmp_buf, 1);
}

void bar() {
  baz();
}

int foo(int x) {
  int a = 0;

  if (setjmp(jmp_buf) == 0) {
    while (1) {
      a = 1;
      bar();  /* OK if baz () instead */
    }
  } else {
    if (a == 0)
      return 0;
    else
      return x;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  if (foo(x) == 0)
    abort();

  return 0;
}
