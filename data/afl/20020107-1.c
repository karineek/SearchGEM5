// Modification timestamp: 2023-08-14 12:07:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020107-1.c

#include <stdio.h>
#include <stdlib.h>

// External function declarations
extern void abort(void);
extern void exit(int);

// Function to check if x is 0
static void bar(int x) {
  if (!x)
    abort();
}

char buf[10];

// Inline function to return tmp + 2
inline char *foo(char *tmp) {
  asm("" : "=r"(tmp) : "0"(tmp));
  return tmp + 2;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int buf_0 = atoi(argv[1]);
  bar((foo(buf) - buf_0 - buf) == 1);

  exit(0);
}
