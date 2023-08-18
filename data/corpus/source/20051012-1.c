// Modification timestamp: 2023-08-14 13:05:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051012-1.c

#include <stdio.h>
#include <stdlib.h>

struct type
{
  int *a;

  int b:16;
  unsigned int p:9;
} t;

unsigned int foo(struct type s)
{
  return s.p;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  t.p = atoi(argv[1]);
  if (foo(t) != atoi(argv[1]))
    abort();
  return 0;
}


//Note: The original program doesn't have any command-line argument handling, so I've added a check for the number of arguments and an error message.