// Modification timestamp: 2023-08-14 14:54:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr32500.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

void foo(int) __attribute__((noinline));
void bar(void) __attribute__((noinline));

int x;
void foo(int i) { x = i; }
void bar(void) { exit(0); }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  int numbers[4] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]) };

  for (i = 1; i <= 12; i++) {
    if (i <= 4)
      foo(numbers[i-1]);
    else if (i >= 7 && i <= 9)
      bar();
  }

  abort();
}

Make sure to pass 4 arguments when executing the program.